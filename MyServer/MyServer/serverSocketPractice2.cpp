#include "pch.h"
#include "socketPractice.h"
#include "serverSocketPractice2.h"
#include "MyMacros.h"
#include <thread>
#include <iostream>

using namespace std;

inline void HandleError() {
	int errorCode = ::WSAGetLastError();
	cout << errorCode << endl;
}

struct recvEvent {
	WSAOVERLAPPED recvOverlapped = {};
	SOCKET connectedSocket;
};

void Dispatch(HANDLE iocpHandle) {
	while (true) {
		DWORD numOfBytes = 0;
		ULONG_PTR key = 0;
		recvEvent* rEvent = nullptr;
		if (::GetQueuedCompletionStatus(
			iocpHandle,
			OUT & numOfBytes,
			OUT & key,
			OUT reinterpret_cast<LPOVERLAPPED*>(&rEvent),
			1000)
			) {
			cout << "recv complete" << endl;
			int buflen = 100;
			char sendbuf[100] = "This is the message.";
			if (SOCKET_ERROR == ::send(rEvent->connectedSocket, sendbuf, buflen, 0)) {
				HandleError();
			}
		}
	}
}

void serverSocketPractice2() {
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
	SOCKET connectedSocketHandle = ::accept(listenSocketHandle, (SOCKADDR*)&clientAddr, &addrLen);
	if (connectedSocketHandle == INVALID_SOCKET) {
		HandleError();
		return;
	}

	HANDLE iocpHandle = ::CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0/*key*/, 5);
	::CreateIoCompletionPort((HANDLE)connectedSocketHandle, iocpHandle, 0/*key*/, 0/*ignored*/);
	
	thread t1(Dispatch, iocpHandle);

	WSADATA wsd;
	recvEvent rEvent;
	SecureZeroMemory((PVOID)&rEvent, sizeof(recvEvent));
	rEvent.connectedSocket = connectedSocketHandle;
	WSABUF DataBuf;
	DWORD RecvBytes, Flags = 0;
	char recvbuf[100];
	DataBuf.len = 100;
	DataBuf.buf = recvbuf;
	while (true) {
		this_thread::sleep_for(2s);
		::WSARecv(connectedSocketHandle, &DataBuf, 1, &RecvBytes, &Flags, (LPOVERLAPPED)&rEvent, NULL);
	}

	t1.join();
}
