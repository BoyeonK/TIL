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
	return false;
}

void Session::Disconnect() {
}

bool Session::RegisterConnect() {
	return false;
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
}

void Session::ProcessDisconnect() {
}

void Session::ProcessRecv(int32_t numOfBytes) {
}

void Session::ProcessSend(int32_t numOfBytes) {
}

void Session::HandleError(int32_t errorCode) {
}
