#include "pch.h"
#include "Session.h"
#include "SocketUtils.h"

//recvBuffer와 sendBuffer는 이후에 새로운 class로서 만들어 줄 것임.
Session::Session() : _recvBuffer("Hello World!"), _sendBuffer("Hello World!") {
	_socketHandle = SocketUtils::CreateSocket();
}

Session::~Session() {
	SocketUtils::Close(_socketHandle);
}

void Session::Send(char* sendBuffer) {
	int32_t bufSize = sizeof(sendBuffer);
	//RegisterSend(sendBuffer);
}

bool Session::Connect() {
	return RegisterConnect();
}

void Session::Disconnect() {
}

HANDLE Session::GetHandle() {
	return reinterpret_cast<HANDLE>(_socketHandle);
}

void Session::Dispatch(CPTask* pCPTask, int32_t numOfBytes) {
	switch (pCPTask->_TaskType) {
	case (TaskType::Connect):
		ProcessConnect();
		break;
	case (TaskType::Disconnect):
		break;
	case (TaskType::Recv):
		break;
	case (TaskType::Send):
		break;
	default:
		break;
	}
}

bool Session::RegisterConnect() {
	if (isConnected()) {
		cout << "??" << endl;
		return false;
	}
		

	//소유한 service객체가 client용인지 확인

	if (SocketUtils::SetReuseAddress(_socketHandle, true) == false)
		return false;

	if (SocketUtils::BindAnyAddress(_socketHandle, 0) == false)
		return false;

	_CT.Init();
	_CT._OwnerRef = shared_from_this();

	DWORD numOfBytes = 0;
	SOCKADDR_IN sockAddr = GetService()->GetAddress().GetSockAddr();
	if (false == SocketUtils::ConnectEx(_socketHandle, reinterpret_cast<SOCKADDR*>(&sockAddr), sizeof(sockAddr), nullptr, 0, &numOfBytes, &_CT)) {
		int errorCode = ::WSAGetLastError();
		if (errorCode != WSA_IO_PENDING) {
#ifdef _DEBUG
			cout << "ConnectEx함수 실행 에러" << endl;
#endif
			_CT._OwnerRef = nullptr;
			return false;
		}
	}

	return true;
}

bool Session::RegisterDisconnect() {
	return false;
}

void Session::RegisterRecv() {
	
}
/*
void Session::RegisterSend(char* sendBuffer) {
	::WSASend(_socketHandle, &sendBuffer, 1, )
}
*/
void Session::ProcessConnect() {
	_CT._OwnerRef = nullptr;
	_connected.store(true);
	GetService()->AddSession(GetSessionRef());
	OnConnected();
	RegisterRecv();
}

void Session::ProcessDisconnect() {
}

void Session::ProcessRecv(int32_t numOfBytes) {
}

void Session::ProcessSend(int32_t numOfBytes) {
}

void Session::HandleError(int32_t errorCode) {
}
