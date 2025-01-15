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
	a->DoTimerAsync([] {cout << "외부 입력 검증 : 모든 입력값을 화이트리스트 방식으로 검증." << endl; }, 500);
	a->DoTimerAsync([] {cout << "안전한 함수 사용 : system, strcpy 대신 안전한 대체 함수 사용." << endl; }, 2000);
	a->DoTimerAsync([] {cout << "메모리 관리 : 포인터와 버퍼 사용 시 크기 제한과 경계 체크." << endl; }, 1250);
	a->DoTimerAsync([] {cout << "컴파일러 보호 옵션 사용 : 스택 보호와 ASLR 활성화." << endl; }, 3550);
	a->DoTimerAsync([] {cout << "정적 분석 도구 활용 : 취약점 탐지 및 코드 검토." << endl; }, 2750);

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