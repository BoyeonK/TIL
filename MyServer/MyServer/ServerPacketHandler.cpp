#include "pch.h"
#include "ServerPacketHandler.h"

PacketHandlerFunc GPacketHandler[UINT16_MAX];

bool Handle_INVALID(shared_ptr<PBSession> sessionRef, unsigned char* buffer, int32_t len) {
	return false;
}

bool Handle_S_CHAT(shared_ptr<PBSession> sessionRef, PB::S_CHAT& pkt) {
	cout << "got a message : " << pkt.msg() << endl;
	return true;
}
