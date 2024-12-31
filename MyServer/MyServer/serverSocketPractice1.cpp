#include "pch.h"
#include "socketPractice.h"
#include "serverSocketPractice1.h"
#include "MyMacros.h"
#include <iostream>

using namespace std;

inline void HandleError() {
	int errorCode = ::WSAGetLastError();
	cout << errorCode << endl;
}

void serverSocketPractice1() {
	//시작
	WSAData wsaData;
	if (::WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		HandleError();
		return;
	}

	//Listen소켓 준비
	SOCKET listenSocketHandle = ::socket(AF_INET, SOCK_STREAM, 0);
	if (listenSocketHandle == INVALID_SOCKET) {
		HandleError();
		return;
	}

	//주소 정의
	SOCKADDR_IN serverAddr;
	::memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = INADDR_ANY;
	serverAddr.sin_port = ::htons(7777);

	//ListenSocket의 handle과 주소로서 Bind
	if (SOCKET_ERROR == ::bind(listenSocketHandle, (SOCKADDR*)&serverAddr, sizeof(serverAddr))) {
		HandleError();
		return;
	}

	//Listen시작. 2번째 인자 backlog는 여러 연결이 들어올 경우
	//보류할 요청 (queue)의 최대 수 이다.
	if (SOCKET_ERROR == ::listen(listenSocketHandle, 10)) {
		HandleError();
		return;
	}

	SOCKET acceptSocket;

	SOCKADDR_IN clientAddr;
	::memset(&clientAddr, 0, sizeof(clientAddr));
	int addrLen = sizeof(clientAddr);

	acceptSocket = ::accept(listenSocketHandle, (SOCKADDR*)&clientAddr, &addrLen);
	if (acceptSocket == INVALID_SOCKET) {
		HandleError();
		return;
	}

	char ipAddress[16];
	::inet_ntop(AF_INET, &clientAddr.sin_addr, ipAddress, sizeof(ipAddress));
	cout << "Client Connected! IP = " << ipAddress << endl;
}
