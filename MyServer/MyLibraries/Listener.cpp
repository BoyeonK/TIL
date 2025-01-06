#include "pch.h"
#include "Listener.h"
#include "SocketUtils.h"

Listener::Listener(NetAddress myaddress) : _myAddress(myaddress) { }

Listener::~Listener() {
	SocketUtils::Close(_socketHandle);
	for (auto p : _pAcceptTasks)
		delete p;
}

bool Listener::StartAccept(HANDLE iocpHandle) {
	//Listen 소켓 생성
	_socketHandle = SocketUtils::CreateSocket();
	if (_socketHandle == INVALID_SOCKET) return false;

	//iocp 핸들이 유효한지 검사
	if (iocpHandle == INVALID_HANDLE_VALUE) return false;

	//소켓의 TIME_WAIT상태일때, 같은 포트로 다른 소켓의 bind요청을 허용
	if (SocketUtils::SetReuseAddress(_socketHandle, true) == false)	return false;

	//TCP 연결이 끊긴 경우, 남은 데이터를 보내줄것인가? (default 보낸다.)
	if (SocketUtils::SetLinger(_socketHandle, 0, 0) == false) return false;

	//Bind시도
	if (SocketUtils::Bind(_socketHandle, _myAddress) == false) return false;

	//Listen시도
	if (SocketUtils::Listen(_socketHandle) == false) return false;

	for (int i = 0; i < 100; i++) {
		AcceptTask* pAcceptTask = new AcceptTask;
		pAcceptTask->_OwnerRef = shared_from_this();
		RegisterAccept(pAcceptTask);
	}

	return true;
}

void Listener::RegisterAccept(AcceptTask* pAcceptTask) {
	//지금은 그냥 session을 만들지만, 나중에 session을 만들 함수를 제공할 예정.
	shared_ptr<Session> sessionRef = make_shared<Session>();

	pAcceptTask->Init();
	pAcceptTask->_sessionRef = sessionRef;
	
	DWORD bytesReceived;
	if (false == SocketUtils::AcceptEx(
		_socketHandle,
		sessionRef->GetSocket(),
		sessionRef->_recvBuffer,
		0,
		sizeof(SOCKADDR_IN) + 16,
		sizeof(SOCKADDR_IN) + 16,
		&bytesReceived,
		pAcceptTask)
		) {
		const int errorCode = ::WSAGetLastError();
		if (errorCode != WSA_IO_PENDING) {
#ifdef _DEBUG
			cout << "Error Occured with errorCode : " << errorCode << endl;
#endif
			RegisterAccept(pAcceptTask);
		}
	}
	
}

void Listener::CloseSocket() {
}

HANDLE Listener::GetHandle() {
	return reinterpret_cast<HANDLE>(_socketHandle);
}

void Listener::Dispatch(CPTask* cptask, int32_t NumOfBytes) {
	
}

void Listener::ProcessAccept(AcceptTask* pAcceptTask) {
	shared_ptr<Session> sessionRef = pAcceptTask->_sessionRef;

	//Listener Socket과 동일한 옵션을 AcceptedSocket에 전달 시도
	if (false == SocketUtils::SetUpdateAcceptSocket(sessionRef->GetSocket(), _socketHandle)) {
		sessionRef == nullptr;
		RegisterAccept(pAcceptTask);
		return;
	}

	SOCKADDR_IN sockAddress;
	int32_t sizeOfSockAddr = sizeof(sockAddress);
	if (SOCKET_ERROR == ::getpeername(sessionRef->GetSocket(), reinterpret_cast<SOCKADDR*>(&sockAddress), &sizeOfSockAddr)) {
		sessionRef == nullptr;
		RegisterAccept(pAcceptTask);
		return;
	}

	sessionRef->SetNetAddress(NetAddress(sockAddress));
	//session->
}

