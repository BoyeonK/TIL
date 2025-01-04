#include "pch.h"
#include "Listener.h"
#include "SocketUtils.h"

Listener::Listener(NetAddress myaddress) : _MyAddress(myaddress) { }

Listener::~Listener() { }

bool Listener::StartAccept(HANDLE iocpHandle) {
	//Listen ���� ����
	_SocketHandle = SocketUtils::CreateSocket();
	if (_SocketHandle == INVALID_SOCKET) return false;

	//iocp �ڵ��� ��ȿ���� �˻�
	if (iocpHandle == INVALID_HANDLE_VALUE) return false;

	//������ TIME_WAIT�����϶�, ���� ��Ʈ�� �ٸ� ������ bind��û�� ���
	if (SocketUtils::SetReuseAddress(_SocketHandle, true) == false)	return false;

	//TCP ������ ���� ���, ���� �����͸� �����ٰ��ΰ�? (default ������.)
	if (SocketUtils::SetLinger(_SocketHandle, 0, 0) == false) return false;

	//Bind�õ�
	if (SocketUtils::Bind(_SocketHandle, _MyAddress) == false) return false;

	//Listen�õ�
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

