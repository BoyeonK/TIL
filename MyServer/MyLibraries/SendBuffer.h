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

	//std::array<_ty>.size()가 int64를 반환하기 때문에
	//형변환을 해주지 않는다면 데이터 손실을 야기할 수 있다.
	int32_t FreeSize() { return static_cast<int32_t>(_buffer.size() - _usedSize); }

private:
	array<unsigned char, SEND_BUFFER_CHUNK_SIZE> _buffer = {};
	//SendBufferChunk는 TLS로 사용할 것이기 때문에 thread-safe
	//atomic으로 만들어 줄 필요가 없다.
	bool _isOpen;
	uint32_t _usedSize;
};

