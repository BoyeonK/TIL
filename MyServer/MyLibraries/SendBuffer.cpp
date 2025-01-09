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
