#include "pch.h"
#include "CoreGlobal.h"
#include "ServiceWithIocp_Server.h"
#include "ServerPacketHandler.h"

class TestSession3 : public PBSession {
	void OnConnected() {
		cout << "Succeed to Accept" << endl;
	}

	void OnRecvPacket(unsigned char* buffer, int32_t len) {
		ServerPacketHandler::HandlePacket(static_pointer_cast<PBSession>(shared_from_this()), buffer, len);
		cout << "message Recv" << endl;
	}
};

shared_ptr<TestSession3> SessionMaker() {
	return make_shared<TestSession3>();
}

void ServiceWithIocp_Server() {
	ServerPacketHandler::Init();

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
