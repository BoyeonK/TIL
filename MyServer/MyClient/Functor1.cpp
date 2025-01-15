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
	a->DoTimerAsync([] {cout << "�ܺ� �Է� ���� : ��� �Է°��� ȭ��Ʈ����Ʈ ������� ����." << endl; }, 500);
	a->DoTimerAsync([] {cout << "������ �Լ� ��� : system, strcpy ��� ������ ��ü �Լ� ���." << endl; }, 2000);
	a->DoTimerAsync([] {cout << "�޸� ���� : �����Ϳ� ���� ��� �� ũ�� ���Ѱ� ��� üũ." << endl; }, 1250);
	a->DoTimerAsync([] {cout << "�����Ϸ� ��ȣ �ɼ� ��� : ���� ��ȣ�� ASLR Ȱ��ȭ." << endl; }, 3550);
	a->DoTimerAsync([] {cout << "���� �м� ���� Ȱ�� : ����� Ž�� �� �ڵ� ����." << endl; }, 2750);

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