#include "pch.h"
#include "SFunctor1.h"
#include "ServiceWithIocp_Server.h"
#include "ServerPacketHandler.h"
//server

void SFunctor1() {
	ServerPacketHandler::Init();
}
