#include "pch.h"
#include "RoomClientSession.h"
#include "ClientPacketHandler.h"

void RoomClientSession::OnDisconnect() {
	//Leave요청 보내기
}

void RoomClientSession::OnRecvPacket(unsigned char* buffer, int32_t len) {
	ClientPacketHandler::HandlePacket(static_pointer_cast<PBSession>(shared_from_this()), buffer, len);
}
