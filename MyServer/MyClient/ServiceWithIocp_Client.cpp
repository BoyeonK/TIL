#include "pch.h"
#include "ServiceWithIocp_Client.h"
#include "CoreGlobal.h"
#include "PB.pb.h"
#include "ClientPacketHandler.h"

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
		maxSessionCount
	) { }

	void BroadCast(shared_ptr<SendBuffer> sendBufferRef) {
		for (shared_ptr<Session> sessionRef : _sessionRefs) {
			sessionRef->Send(sendBufferRef);
		}
	}
};

//Client에서 Session을 상속받음
class CustomClientSession : public PBSession {
	void OnConnected() {
		cout << "Connected to server" << endl;
	}

	void OnRecvPacket(unsigned char* buffer, int32_t len) {
		cout << "Recv!" << endl;
	}
};

shared_ptr<CustomClientSession> CCSmaker() {
	return make_shared<CustomClientSession>();
}

void ServiceWithIocp_Client() {
	ClientPacketHandler::Init();

	shared_ptr<CustomClientService> CS = make_shared<CustomClientService>(
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

	int32_t pid = 0;
	this_thread::sleep_for(3s);


	while (true) {
		PB::S_CHAT pkt;
		string message = "This Message is serialized by PB";
		pkt.set_playerid(pid++);
		pkt.set_msg(message);
		shared_ptr<SendBuffer> SendBufferRef = ClientPacketHandler::MakeSendBufferRef(pkt);
		CS->BroadCast(SendBufferRef);
		this_thread::sleep_for(1s);
	}

	GThreadManager->Join();
}