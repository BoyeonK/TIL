#pragma once
#include <vector>
#include "Service.h"

class ServerService;

class Listener : public CPObject {
public:
	Listener() = default;
	~Listener();

	bool StartAccept();
	void CloseSocket();

	virtual HANDLE GetHandle() override;
	virtual void Dispatch(CPTask* pCpTask, int32_t NumOfBytes = 0) override;

	void SetServerService(weak_ptr<ServerService> ServerServiceWRef) {
		_serverServiceWRef = ServerServiceWRef;
	}

private:
	void RegisterAccept(AcceptTask* pAcceptTask);
	void ProcessAccept(AcceptTask* pAcceptTask);

protected:
	SOCKET _socketHandle = INVALID_SOCKET;
	vector<AcceptTask*> _pAcceptTasks;
	weak_ptr<ServerService> _serverServiceWRef;
};

