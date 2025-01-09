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

	ASSERT_CRASH(allocSize <= FreeSize());

	_isOpen = true;
	shared_ptr<SendBuffer> SendBufferRef(objectPool<SendBuffer>::alloc(), objectPool<SendBuffer>::dealloc);
	return SendBufferRef;
}

void SendBufferChunk::Close(uint32_t allocSize) {
	ASSERT_CRASH(_isOpen == true);
	_isOpen = false;
	_usedSize += allocSize;
}
