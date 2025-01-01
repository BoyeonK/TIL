#pragma once
#include "CompletionPortCore.h"
#include <vector>

class Listener : public CPObject {
public:
	Listener(NetAddress myaddress);
	~Listener();

	bool StartAccept(HANDLE iocpHandle);
	void CloseSocket();

	virtual HANDLE GetHandle() override;
	virtual void Dispatch(CPTask* cptask, int32_t NumOfBytes = 0) override;

private:
	void RegisterAccept(AcceptTask*);
	void ProcessAccept(AcceptTask*);

protected:
	SOCKET _SocketHandle = INVALID_SOCKET;
	NetAddress _MyAddress = {};
};

