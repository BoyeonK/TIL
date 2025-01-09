#include "pch.h"
#include "SendBuffer.h"

void SendBufferChunk::Init() {
	_isOpen = false;
	_usedSize = 0;
}

shared_ptr<SendBuffer> SendBufferChunk::Open(uint32_t allocSize) {
	//���������� SEND_BUFFER_CHUNKũ�⺸�� ū ����Ʈ�� send�� �� ����
	ASSERT_CRASH(allocSize <= SEND_BUFFER_CHUNK_SIZE);

	//���� ���� �̹� �����ִ°��� ���� �߸��Ǿ���.
	//�ʱ�ȭ�� �߸���ų�, Close()�� �������� �ʾҴ�.
	ASSERT_CRASH(_isOpen == false);

	//���� ������ ������ ���, nullptr�� ����.
	//�̰��� Ʈ���Ű� �Ǽ� nullptr�� ������ ���, Manager���� �� chunk�� �Ҵ��� �� ����.
	if (allocSize > FreeSize())
		return nullptr;

	_isOpen = true;
	shared_ptr<SendBuffer> SendBufferRef(objectPool<SendBuffer>::alloc(shared_from_this(), Index(), allocSize), objectPool<SendBuffer>::dealloc);
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
