#include "pch.h"
#include "serverSocketPractice3.h"

class TestSession3 : public Session {
	void OnConnected() {
		cout << "Succeed to Accept" << endl;
	}
};

shared_ptr<TestSession3> SessionMaker() {
	return make_shared<TestSession3>();
}

void serverSocketPractice3() {
	SocketUtils::Init();

	shared_ptr<ServerService> SS = make_shared<ServerService>(
		make_shared<CPCore>(),
		NetAddress(L"127.0.0.1", 7777),
		SessionMaker,
		1
	);

	SS->StartAccept();

	if (SS == nullptr) {
		cout << "err" << endl;
	}
	if (SS->GetCPCoreRef()->GetHandle() == INVALID_HANDLE_VALUE) {
		cout << "err" << endl;
	}

	while (true) {
		SS->GetCPCoreRef()->Dispatch();
	}
}
