#include "pch.h"
#include "Session.h"
#include "SocketUtils.h"

Session::Session() {
	_socketHandle = SocketUtils::CreateSocket();
}

Session::~Session() {
	SocketUtils::Close(_socketHandle);
}

void Session::Send() {
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

void Session::RegisterSend() {
}

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
