#pragma once
#include <array>

class SendBuffer {
private:
	char* _sendBuffer;
};

class SendBufferChunk {
public:
	enum {
		SEND_BUFFER_CHUNK_SIZE = 6000,
	};

	void Init();
	shared_ptr<SendBuffer> Open(uint32_t allocSize);
	void Close(uint32_t allocSize);

	bool IsOpen() { return _isOpen; };
	unsigned char* Buffer() { return &_buffer[_usedSize]; }

	//std::array<_ty>.size()�� int64�� ��ȯ�ϱ� ������
	//����ȯ�� ������ �ʴ´ٸ� ������ �ս��� �߱��� �� �ִ�.
	int32_t FreeSize() { return static_cast<int32_t>(_buffer.size() - _usedSize); }

private:
	array<unsigned char, SEND_BUFFER_CHUNK_SIZE> _buffer = {};
	//SendBufferChunk�� TLS�� ����� ���̱� ������ thread-safe
	//atomic���� ����� �� �ʿ䰡 ����.
	bool _isOpen;
	uint32_t _usedSize;
};

