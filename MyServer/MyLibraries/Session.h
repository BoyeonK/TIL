#pragma once
#include "pch.h"
#include "CompletionPortCore.h"
#include "NetAddress.h"

using namespace std;

class Session : public CPObject {
	friend class Listener;
	friend class CPCore;
	friend class Service;

public:
	Session();
	~Session();

	void Send();
	bool Connect();
	void Disconnect();

private:
	bool				RegisterConnect();
	bool				RegisterDisconnect();
	void				RegisterRecv();
	void				RegisterSend();

	void				ProcessConnect();
	void				ProcessDisconnect();
	void				ProcessRecv(int32_t numOfBytes);
	void				ProcessSend(int32_t numOfBytes);

	void				HandleError(int32_t errorCode);

private:
	USE_RWLOCK;
	weak_ptr<Service> _serviceWRef;
	NetAddress _address;
	SOCKET _socketHandle;
	char* _recvBuffer[100];
};

