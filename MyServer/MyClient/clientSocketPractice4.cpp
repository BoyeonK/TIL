#include "pch.h"
#include "clientSocketPractice4.h"
#include "CoreGlobal.h"

class CustomClientSession : public Session {
	void OnConnected() {
		cout << "Connected to server" << endl;
	}
};

shared_ptr<CustomClientSession> CCSmaker() {
	return make_shared<CustomClientSession>();
}

void clientSocketPractice4() {
	shared_ptr<ClientService> CS = make_shared<ClientService>(
		make_shared<CPCore>(),
		NetAddress(L"127.0.0.1", 7777),
		CCSmaker,
		1
	);

	CS->StartConnect();

	GThreadManager->Launch([=]() {
		while (true) {
			CS->GetCPCoreRef()->Dispatch();
		}
	});
	GThreadManager->Join();
}