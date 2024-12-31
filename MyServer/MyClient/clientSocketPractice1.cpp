#include "pch.h"
#include "socketPractice.h"
#include "clientSocketPractice1.h"
#include "MyMacros.h"
#include <iostream>
#include <thread>

using namespace std;

inline void HandleError() {
	int errorCode = ::WSAGetLastError();
	cout << errorCode << endl;
}

void clientServerPractice1() {
	//시작
	WSAData wsaData;
	if (::WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		CRASH("Failed to call WSAStartup function (client)");
	}

	//client socket handle생성
	SOCKET clientSocketHandle = ::socket(AF_INET, SOCK_STREAM, 0);
	if (clientSocketHandle == INVALID_SOCKET) {
		HandleError();
		return;
	}

	//서버 주소 정의
	SOCKADDR_IN serverAddr;
	serverAddr.sin_family = AF_INET;
	::inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);
	serverAddr.sin_port = htons(7777);

	//connect 시도
	if (SOCKET_ERROR == ::connect(clientSocketHandle, (SOCKADDR*)&serverAddr, sizeof(serverAddr))) {
		HandleError();
	}
	cout << "Connected to Server" << endl;

	//buffer에 string장전한다.
	int buflen = 100;
	char sendbuf[100] = "This is the message.";
	char recvbuf[100] = "";

	//send요청 보낸 후, recv한다.
	while (true) {
		this_thread::sleep_for(2s);
		if (SOCKET_ERROR == ::send(clientSocketHandle, sendbuf, buflen, 0)) {
			HandleError();
		}
		int recvlen = ::recv(clientSocketHandle, recvbuf, 100, 0);

		if (recvlen <= 0)
			HandleError();
		cout << recvbuf << endl;
		cout << "recv length is " << recvlen << endl;
	}

	::closesocket(clientSocketHandle);

	::WSACleanup();
}