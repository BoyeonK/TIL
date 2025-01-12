#pragma once
class RoomClientSession : public PBSession {
	void OnDisconnect();
	void OnRecvPacket(unsigned char* buffer, int32_t len) override;
};

