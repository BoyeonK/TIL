#pragma once
#include "CompletionPortCore.h"
#include "Service.h"
#include "NetAddress.h"
#include "RecvBuffer.h"

using namespace std;

class Session : public CPObject {
	friend class Listener;
	friend class CPCore;
	friend class Service;

	enum {
		BUFFER_SIZE = 0x10000,
	};

public:
	Session();
	~Session();

	void Send(char* sendBuffer, int32_t bufSize);
	bool Connect();
	void Disconnect();

public:
	SOCKET GetSocket() { return _socketHandle; }
	void SetNetAddress(NetAddress addr) { _address = addr; }
	void SetServiceWRef(weak_ptr<Service>serviceWRef) { _serviceWRef = serviceWRef; }
	shared_ptr<Service> GetService() { return _serviceWRef.lock(); }
	shared_ptr<Session> GetSessionRef() { return static_pointer_cast<Session>(shared_from_this()); }
	bool isConnected() { return _connected; }
	
private:
	virtual HANDLE GetHandle() override;
	virtual void Dispatch(CPTask* pCPTask, int32_t numOfBytes) override;

private:
	bool				RegisterConnect();
	bool				RegisterDisconnect();
	void				RegisterRecv();
	void				RegisterSend(char* sendBuffer, int32_t numOfBytes);

	void				ProcessConnect();
	void				ProcessDisconnect();
	void				ProcessRecv(int32_t numOfBytes);
	void				ProcessSend(int32_t numOfBytes);

	void				HandleError(int32_t errorCode);

protected:
	virtual void OnConnected() { }
	virtual void OnDisconnected() { }
	virtual void OnSend() { }
	virtual int32_t OnRecv(char* buffer, int32_t len) { return len; }

private:
	USE_RWLOCK;
	//weak_ptr<Service> _serviceWRef;
	NetAddress _address;
	SOCKET _socketHandle;
	atomic<bool> _connected = false;
	weak_ptr<Service> _serviceWRef;
	RecvBuffer _RecvBuffer;
	
	//send버퍼 테스트 코드.
	//send요청은 여러 쓰레드에 의해 일어날 수 있으므로, 이 방식은 나중에 교체되어야 함.
	char _sendBuffer[1000];

private:
	ConnectTask _CT;
	DisconnectTask _DCT;
	RecvTask _RT;
	SendTask _ST;
};

struct PacketHeader {
	uint16_t _size;
	uint16_t _id;
};

class PBSession : public Session {
public:
	PBSession() { }
	~PBSession() { }

protected:
	//virtual int32_t OnRecv(char* buffer, int32_t len) sealed;
	virtual void OnRecvPacket(unsigned char* buffer, int32_t len) abstract;
};
