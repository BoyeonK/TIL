#include "pch.h"
#include "RoomServerSession.h"
#include "ServerPacketHandler.h"

void RoomServerSession::OnConnected() {
	//TODO: C_CONNECTION ��Ŷ �����ϱ�
	PB::C_CONNECTION responseConnectPKT;
	responseConnectPKT.set_isvalid(true);
	shared_ptr<SendBuffer>sendBuff = ServerPacketHandler::MakeSendBufferRef(responseConnectPKT);
	Send(sendBuff);
	cout << "client ����! �α����� �����ϵ��� ��Ŷ�� ����" << endl;
}

void RoomServerSession::OnRecvPacket(unsigned char* buffer, int32_t len) {
	ServerPacketHandler::HandlePacket(static_pointer_cast<PBSession>(shared_from_this()), buffer, len);
}
