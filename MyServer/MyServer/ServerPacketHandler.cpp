#include "pch.h"
#include "ServerPacketHandler.h"

PacketHandlerFunc GPacketHandler[UINT16_MAX];

bool Handle_INVALID(shared_ptr<PBSession> sessionRef, unsigned char* buffer, int32_t len) {
	return false;
}

bool Handle_S_CHAT(shared_ptr<PBSession> sessionRef, PB::S_CHAT& pkt) {
	cout << "Chat Message from " << pkt.playerid() << " : " << pkt.msg() << endl;
	PB::C_CHAT c_chat_pkt;
	string c_msg = "chat request from " + to_string(pkt.playerid()) + "is succeed!";
	c_chat_pkt.set_msg(c_msg);
	shared_ptr<SendBuffer> sendBufferRef = ServerPacketHandler::MakeSendBufferRef(c_chat_pkt);
	sessionRef->Send(sendBufferRef);
	return true;
}
