#include "pch.h"
#include "socketPractice.h"
#include "clientSocketPractice1.h"
#include "MyMacros.h"
#include <iostream>

using namespace std;

inline void HandleError() {
	int errorCode = ::WSAGetLastError();
	cout << errorCode << endl;
}

void clientServerPractice1() {
	WSAData wsaData;
	if (::WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		CRASH("Failed to call WSAStartup function (client)");
	}

	SOCKET clientSocketHandle = ::socket(AF_INET, SOCK_STREAM, 0);
	if (clientSocketHandle == INVALID_SOCKET) {
		HandleError();
		return;
	}

	SOCKADDR_IN serverAddr;
	serverAddr.sin_family = AF_INET;
	::inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);
	serverAddr.sin_port = htons(7777);

	if (SOCKET_ERROR == ::connect(clientSocketHandle, (SOCKADDR*)&serverAddr, sizeof(serverAddr))) {
		HandleError();
	}
	cout << "Connected to Server" << endl;

	::closesocket(clientSocketHandle);

	::WSACleanup();
}