#pragma once
class RoomServerSession : public PBSession {
	void OnConnected();
	void OnDisconnected();
	void OnRecvPacket(unsigned char* buffer, int32_t len) override;
};

