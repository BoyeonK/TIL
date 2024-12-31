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

	//Accept하기 전, connect요청을 보낸 Client의 정보를 저장할 변수
	SOCKADDR_IN clientAddr;
	::memset(&clientAddr, 0, sizeof(clientAddr));
	int addrLen = sizeof(clientAddr);

	//Accept실행, 연결 완료된 소켓 생성, 현재 방식은 Blocking방식이다.
	SOCKET connectedSocket = ::accept(listenSocketHandle, (SOCKADDR*)&clientAddr, &addrLen);
	if (connectedSocket == INVALID_SOCKET) {
		HandleError();
		return;
	}

	//Accept가 완료되면 연결된 Client의 정보가 담기는 것을 확인할 수 있다.
	char ipAddress[16];
	::inet_ntop(AF_INET, &clientAddr.sin_addr, ipAddress, sizeof(ipAddress));
	cout << "Client Connected! IP = " << ipAddress << endl;

	char recvbuf[100] = "";

	//연결된 client 소켓에 대해 recv를 수행 후,
	//받은 buffer와 동일한 버퍼를 다시 send한다.
	while (true) {
		int recvlen = ::recv(connectedSocket, recvbuf, 100, 0);
		if (recvlen <= 0)
			HandleError();
		cout << recvbuf << endl;
		cout << "recv length is " << recvlen << endl;

		if (SOCKET_ERROR == ::send(connectedSocket, recvbuf, recvlen, 0)) {
			HandleError();
			return;
		}
	}

	::closesocket(connectedSocket);

	::WSACleanup();
}
