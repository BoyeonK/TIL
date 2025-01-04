#include "pch.h"
#include "Listener.h"
#include "SocketUtils.h"

Listener::Listener(NetAddress myaddress) : _MyAddress(myaddress) { }

Listener::~Listener() { }

bool Listener::StartAccept(HANDLE iocpHandle) {
	//Listen 소켓 생성
	_SocketHandle = SocketUtils::CreateSocket();
	if (_SocketHandle == INVALID_SOCKET) return false;

	//iocp 핸들이 유효한지 검사
	if (iocpHandle == INVALID_HANDLE_VALUE) return false;

	//소켓의 TIME_WAIT상태일때, 같은 포트로 다른 소켓의 bind요청을 허용
	if (SocketUtils::SetReuseAddress(_SocketHandle, true) == false)	return false;

	//TCP 연결이 끊긴 경우, 남은 데이터를 보내줄것인가? (default 보낸다.)
	if (SocketUtils::SetLinger(_SocketHandle, 0, 0) == false) return false;

	//Bind시도
	if (SocketUtils::Bind(_SocketHandle, _MyAddress) == false) return false;

	//Listen시도
	if (SocketUtils::Listen(_SocketHandle) == false) return false;

	for (int i = 0; i < 100; i++) {
		AcceptTask* acceptTask = new AcceptTask;
		acceptTask->_OwnerRef = shared_from_this();
		RegisterAccept(acceptTask);
	}

	return true;
}

void Listener::RegisterAccept(AcceptTask* acceptTask) {
	//SocketUtils::AcceptEx(_SocketHandle, )
}

void Listener::CloseSocket() {
}

HANDLE Listener::GetHandle() {
	return reinterpret_cast<HANDLE>(_SocketHandle);
}

void Listener::Dispatch(CPTask* cptask, int32_t NumOfBytes) {
	
}

void Listener::ProcessAccept(AcceptTask*) {
}

