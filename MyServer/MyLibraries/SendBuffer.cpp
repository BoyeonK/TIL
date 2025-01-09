#include "pch.h"
#include "SendBuffer.h"

void SendBufferChunk::Init() {
	_isOpen = false;
	_usedSize = 0;
}

shared_ptr<SendBuffer> SendBufferChunk::Open(uint32_t allocSize) {
	//구조적으로 SEND_BUFFER_CHUNK크기보다 큰 바이트는 send할 수 없음
	ASSERT_CRASH(allocSize <= SEND_BUFFER_CHUNK_SIZE);

	//열기 전에 이미 열려있는것은 무언가 잘못되었다.
	//초기화가 잘못됬거나, Close()가 동작하지 않았다.
	ASSERT_CRASH(_isOpen == false);

	//남은 공간이 부족할 경우, nullptr을 리턴.
	//이것이 트리거가 되서 nullptr을 리턴한 경우, Manager에서 새 chunk를 할당해 줄 것임.
	if (allocSize > FreeSize())
		return nullptr;

	_isOpen = true;
	shared_ptr<SendBuffer> SendBufferRef = { objectPool<SendBuffer>::alloc(shared_from_this(), Index(), allocSize), objectPool<SendBuffer>::dealloc };
	return SendBufferRef;
}

void SendBufferChunk::Close(uint32_t allocSize) {
	ASSERT_CRASH(_isOpen == true);
	_isOpen = false;
	_usedSize += allocSize;
}

SendBuffer::SendBuffer(
	shared_ptr<SendBufferChunk> chunkRef, 
	unsigned char* index, 
	uint32_t allocSize)
:
	_chunkRef(chunkRef),
	_index(index),
	_allocSize(allocSize)
{ }

shared_ptr<SendBuffer> SendBufferManager::Open(uint32_t allocSize) {
	if (LSendBufferChunkRef == nullptr or LSendBufferChunkRef->FreeSize() < allocSize) {
		shared_ptr<SendBufferChunk> newChunk = { objectPool<SendBufferChunk>::alloc(), objectPool<SendBufferChunk>::dealloc };
		LSendBufferChunkRef = newChunk;
	}
	ASSERT_CRASH(LSendBufferChunkRef->IsOpen() == false);

	return LSendBufferChunkRef->Open(allocSize);
}
