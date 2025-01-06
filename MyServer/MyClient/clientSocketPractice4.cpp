#include "pch.h"
#include "clientSocketPractice4.h"

class CustomClientSession : public Session {
	void OnConnected() {
		cout << "Connected to server" << endl;
	}
};

shared_ptr<CustomClientSession> CCSmaker() {
	return make_shared<CustomClientSession>();
}

void clientSocketPractice4() {
	SocketUtils::Init();

	this_thread::sleep_for(2s);
	shared_ptr<ClientService> CS = make_shared<ClientService>(
		make_shared<CPCore>(),
		NetAddress(L"127.0.0.1", 7777),
		CCSmaker,
		1
	);

	CS->StartConnect();

	if (CS == nullptr) {
		cout << "err" << endl;
	}
	if (CS->GetCPCoreRef()->GetHandle() == INVALID_HANDLE_VALUE) {
		cout << "err" << endl;
	}

	while (true) {
		CS->GetCPCoreRef()->Dispatch();
	}
}