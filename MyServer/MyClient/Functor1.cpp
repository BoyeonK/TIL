#include "pch.h"
#include "Functor1.h"
#include "CoreGlobal.h"
#include "ClientPacketHandler.h"
#include "RoomClientSession.h"

shared_ptr<RoomClientSession> MakeSession() {
	return make_shared<RoomClientSession>();
}

class voidStruct : public JobQueue {};

//Client
void Functor1() {
	ClientPacketHandler::Init();

	shared_ptr<ClientService> CS = make_shared<ClientService>(
		make_shared<CPCore>(),
		NetAddress(L"127.0.0.1", 7777),
		MakeSession,
		5
	);

	shared_ptr<voidStruct> a = make_shared<voidStruct>();
	a->DoTimerAsync([] {cout << "이거 아무 void타입 함수나 넣을수 있어서" << endl; }, 500);
	a->DoTimerAsync([] {cout << "상당히 좆될 수 있는 부분인거 같은데?" << endl; }, 2000);
	a->DoTimerAsync([] {cout << "코드인젝션 당하면" << endl; }, 1250);

	GThreadManager->Launch([]() {
		while (true) {
			ThreadManager::DoTimerQueueDistribution();
			this_thread::sleep_for(50ms);
		}
	});

	for (int i = 0; i < 4; i++) {
		GThreadManager->Launch([=]() {
			while (true) {
				LEndTickCount = ::GetTickCount64() + 64;
				ThreadManager::DoGlobalQueueWork();
				CS->GetCPCoreRef()->Dispatch(10);
			}
		});
	}

	this_thread::sleep_for(3s);

	CS->StartConnect();

	GThreadManager->Join();
}