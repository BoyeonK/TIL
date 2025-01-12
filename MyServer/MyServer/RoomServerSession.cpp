#include "pch.h"
#include "RoomServerSession.h"
#include "ServerPacketHandler.h"

void RoomServerSession::OnConnected() {
	//TODO: C_CONNECTION 패킷 전송하기
	PB::C_CONNECTION responseConnectPKT;
	responseConnectPKT.set_isvalid(true);
	shared_ptr<SendBuffer>sendBuff = ServerPacketHandler::MakeSendBufferRef(responseConnectPKT);
	Send(sendBuff);
	cout << "client 연결! 로그인을 유도하도록 패킷을 전송" << endl;
}

void RoomServerSession::OnRecvPacket(unsigned char* buffer, int32_t len) {
	ServerPacketHandler::HandlePacket(static_pointer_cast<PBSession>(shared_from_this()), buffer, len);
}
