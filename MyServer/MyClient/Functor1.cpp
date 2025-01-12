#include "pch.h"
#include "Functor1.h"
#include "CoreGlobal.h"
#include "ClientPacketHandler.h"
#include "RoomClientSession.h"

shared_ptr<RoomClientSession> MakeSession() {
	return make_shared<RoomClientSession>();
}

//Client
void Functor1() {
	ClientPacketHandler::Init();

	shared_ptr<ClientService> CS = make_shared<ClientService>(
		make_shared<CPCore>(),
		NetAddress(L"127.0.0.1", 7777),
		MakeSession,
		5
	);

	this_thread::sleep_for(3s);

	CS->StartConnect();

	GThreadManager->Launch([=]() {
		while (true) {
			CS->GetCPCoreRef()->Dispatch();
		}
	});

	GThreadManager->Join();
}