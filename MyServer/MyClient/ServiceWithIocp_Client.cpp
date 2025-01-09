#include "pch.h"
#include "ServiceWithIocp_Client.h"
#include "CoreGlobal.h"

//Client에서 Service를 상속받음
class CustomClientService : public ClientService {
public:
	CustomClientService(
		shared_ptr<CPCore>CPCoreRef,
		NetAddress address,
		SessionFactory sessionFactory,
		uint32_t maxSessionCount = 1) 
: 
	ClientService(
		CPCoreRef,
		address,
		sessionFactory,
		maxSessionCount)
	{ }

	shared_ptr<Session> CustomStart() {
		if (CanStart() == false)
			return nullptr;

		shared_ptr<Session> sessionRef = CreateSessionRef();
		sessionRef->Connect();
		return sessionRef;
	}
};

//Client에서 Session을 상속받음
class CustomClientSession : public Session {
	void OnConnected() {
		cout << "Connected to server" << endl;
	}
};

shared_ptr<CustomClientSession> CCSmaker() {
	return make_shared<CustomClientSession>();
}

void ServiceWithIocp_Client() {
	shared_ptr<CustomClientService> CS = make_shared<CustomClientService>(
		make_shared<CPCore>(),
		NetAddress(L"127.0.0.1", 7777),
		CCSmaker,
		1
	);

	shared_ptr<Session> CustomSession = CS->CustomStart();
	char message[100] = "Hello World!";

	GThreadManager->Launch([=]() {
		while (true) {
			CS->GetCPCoreRef()->Dispatch();
		}
	});

	this_thread::sleep_for(3s);

	while (true) {
		shared_ptr<SendBuffer> SendBufferRef = GSendBufferManager->Open(150);
		char* msg = reinterpret_cast<char*>(SendBufferRef->Buffer());
		strcpy_s(msg, 150, "Sent by new objects!");
		SendBufferRef->Close(100);
		CustomSession->Send(msg, 100);
		this_thread::sleep_for(0.5s);
	}

	GThreadManager->Join();
}