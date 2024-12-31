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
	//����
	WSAData wsaData;
	if (::WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
		HandleError();
		return;
	}

	//Listen���� �غ�
	SOCKET listenSocketHandle = ::socket(AF_INET, SOCK_STREAM, 0);
	if (listenSocketHandle == INVALID_SOCKET) {
		HandleError();
		return;
	}

	//�ּ� ����
	SOCKADDR_IN serverAddr;
	::memset(&serverAddr, 0, sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = INADDR_ANY;
	serverAddr.sin_port = ::htons(7777);

	//ListenSocket�� handle�� �ּҷμ� Bind
	if (SOCKET_ERROR == ::bind(listenSocketHandle, (SOCKADDR*)&serverAddr, sizeof(serverAddr))) {
		HandleError();
		return;
	}

	//Listen����. 2��° ���� backlog�� ���� ������ ���� ���
	//������ ��û (queue)�� �ִ� �� �̴�.
	if (SOCKET_ERROR == ::listen(listenSocketHandle, 10)) {
		HandleError();
		return;
	}

	//Accept�ϱ� ��, connect��û�� ���� Client�� ������ ������ ����
	SOCKADDR_IN clientAddr;
	::memset(&clientAddr, 0, sizeof(clientAddr));
	int addrLen = sizeof(clientAddr);

	//Accept����, ���� �Ϸ�� ���� ����, ���� ����� Blocking����̴�.
	SOCKET connectedSocket = ::accept(listenSocketHandle, (SOCKADDR*)&clientAddr, &addrLen);
	if (connectedSocket == INVALID_SOCKET) {
		HandleError();
		return;
	}

	//Accept�� �Ϸ�Ǹ� ����� Client�� ������ ���� ���� Ȯ���� �� �ִ�.
	char ipAddress[16];
	::inet_ntop(AF_INET, &clientAddr.sin_addr, ipAddress, sizeof(ipAddress));
	cout << "Client Connected! IP = " << ipAddress << endl;

	char recvbuf[100] = "";

	//����� client ���Ͽ� ���� recv�� ���� ��,
	//���� buffer�� ������ ���۸� �ٽ� send�Ѵ�.
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
