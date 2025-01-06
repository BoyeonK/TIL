#pragma once
#include "CompletionPortCore.h"
#include "Service.h"
#include "NetAddress.h"

using namespace std;

class Session : public CPObject {
	friend class Listener;
	friend class CPCore;
	friend class Service;

public:
	Session();
	~Session();

	void Send(char* sendBuffer);
	bool Connect();
	void Disconnect();

public:
	SOCKET GetSocket() { return _socketHandle; }
	void SetNetAddress(NetAddress addr) { _address = addr; }
	
private:
	virtual HANDLE GetHandle() override;
	virtual void Dispatch(CPTask* pCPTask, int32_t numOfBytes) override;

private:
	bool				RegisterConnect();
	bool				RegisterDisconnect();
	void				RegisterRecv();
	//void				RegisterSend(char* sendBuffer);

	void				ProcessConnect();
	void				ProcessDisconnect();
	void				ProcessRecv(int32_t numOfBytes);
	void				ProcessSend(int32_t numOfBytes);

	void				HandleError(int32_t errorCode);

private:
	USE_RWLOCK;
	//weak_ptr<Service> _serviceWRef;
	NetAddress _address;
	SOCKET _socketHandle;
	char _recvBuffer[1000];
	
	//send버퍼 테스트 코드.
	//send요청은 여러 쓰레드에 의해 일어날 수 있으므로, 이 방식은 나중에 교체되어야 함.
	char _sendBuffer[1000];
};

