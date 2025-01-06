#pragma once
#include "CompletionPortCore.h"
#include "NetAddress.h"
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
	void RegisterAccept(AcceptTask* pAcceptTask);
	void ProcessAccept(AcceptTask* pAcceptTask);

protected:
	SOCKET _socketHandle = INVALID_SOCKET;
	vector<AcceptTask*> _pAcceptTasks;
	NetAddress _myAddress = {};
};

