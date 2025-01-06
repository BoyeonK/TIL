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
	//Listen ���� ����
	_socketHandle = SocketUtils::CreateSocket();
	if (_socketHandle == INVALID_SOCKET) return false;

	//iocp �ڵ��� ��ȿ���� �˻�
	if (iocpHandle == INVALID_HANDLE_VALUE) return false;

	//������ TIME_WAIT�����϶�, ���� ��Ʈ�� �ٸ� ������ bind��û�� ���
	if (SocketUtils::SetReuseAddress(_socketHandle, true) == false)	return false;

	//TCP ������ ���� ���, ���� �����͸� �����ٰ��ΰ�? (default ������.)
	if (SocketUtils::SetLinger(_socketHandle, 0, 0) == false) return false;

	//Bind�õ�
	if (SocketUtils::Bind(_socketHandle, _myAddress) == false) return false;

	//Listen�õ�
	if (SocketUtils::Listen(_socketHandle) == false) return false;

	for (int i = 0; i < 100; i++) {
		AcceptTask* pAcceptTask = new AcceptTask;
		pAcceptTask->_OwnerRef = shared_from_this();
		RegisterAccept(pAcceptTask);
	}

	return true;
}

void Listener::RegisterAccept(AcceptTask* pAcceptTask) {
	//������ �׳� session�� ��������, ���߿� session�� ���� �Լ��� ������ ����.
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

	//Listener Socket�� ������ �ɼ��� AcceptedSocket�� ���� �õ�
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

