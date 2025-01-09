#include "pch.h"
#include "ClientPacketHandler.h"

PacketHandlerFunc GPacketHandler[UINT16_MAX];

bool Handle_INVALID(shared_ptr<PBSession> sessionRef, unsigned char* buffer, int32_t len) {
	return false;
}

bool Handle_C_CHAT(shared_ptr<PBSession> sessionRef, PB::C_CHAT& pkt) {
	cout << "got a message : " << pkt.msg() << endl;
	return false;
}
