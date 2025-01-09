#include "pch.h"
#include "CoreGlobal.h"
#include "ServiceWithIocp_Server.h"

class TestSession3 : public Session {
	void OnConnected() {
		cout << "Succeed to Accept" << endl;
	}

	int32_t OnRecv(char* buffer, int32_t len) {
		cout << "message Recv" << endl;
		return len;
	}
};

shared_ptr<TestSession3> SessionMaker() {
	return make_shared<TestSession3>();
}

void ServiceWithIocp_Server() {
	shared_ptr<ServerService> SS = make_shared<ServerService>(
		make_shared<CPCore>(),
		NetAddress(L"127.0.0.1", 7777),
		SessionMaker,
		1
	);

	SS->StartAccept();

	GThreadManager->Launch([=]() {
		while (true) {
			SS->GetCPCoreRef()->Dispatch();
		}
	});
	GThreadManager->Join();
}
