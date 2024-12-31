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


}