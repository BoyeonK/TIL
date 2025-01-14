#include "pch.h"
#include "SFunctor1.h"
#include "ServiceWithIocp_Server.h"
#include "Service.h"
#include "ServerPacketHandler.h"
#include "Room.h"
#include "RoomServerSession.h"
#include "RoomServerService.h"
//server

shared_ptr<RoomServerSession> makeRS() {
	return make_shared<RoomServerSession>();
}

void SFunctor1() {
	ServerPacketHandler::Init();

	shared_ptr<RoomServerService> RS = make_shared<RoomServerService>(
		make_shared<CPCore>(),
		NetAddress(L"127.0.0.1", 7777),
		makeRS,
		100,
		make_shared<Room>()
	);

	RS->StartAccept();

	for (int i = 0; i < 2; i++) {
		GThreadManager->Launch([=]() {
			while (true) {
				RS->GetCPCoreRef()->Dispatch();
			}
		});
	}
	for (int i = 0; i < 2; i++) {
		GThreadManager->Launch([=]() {
			ThreadManager::DoGlobalQueueWork();
		});
	}

	GThreadManager->Join();
}
