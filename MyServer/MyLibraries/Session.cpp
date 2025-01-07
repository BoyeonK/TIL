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
	RegisterSend(sendBuffer, bufSize);
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
		ProcessSend(numOfBytes);
		break;
	default:
		break;
	}
}

bool Session::RegisterConnect() {
	if (isConnected()) 
		return false;
		
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

void Session::RegisterSend(char* sendBuffer, int32_t numOfBytes) {
	_ST.Init();
	_ST._OwnerRef = shared_from_this();

	WSABUF wsaBuf;
	wsaBuf.buf = sendBuffer;
	wsaBuf.len = static_cast<ULONG>(numOfBytes);
	DWORD bytesSent = 0;
	DWORD flags = 0;
	if (SOCKET_ERROR == ::WSASend(_socketHandle, &wsaBuf, 1, &bytesSent, flags, &_ST, nullptr)) {
		int32_t errorCode = WSAGetLastError();
		if (errorCode != WSA_IO_PENDING) {
			_ST._OwnerRef = nullptr;
		}
	}
}

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
	cout << numOfBytes << " is sent completely" << endl;
	_ST._OwnerRef = nullptr;
}

void Session::HandleError(int32_t errorCode) {
}
