#pragma once
#include "PB.pb.h"
#include "Structs.pb.h"
#include "Enums.pb.h"

using PacketHandlerFunc = function<bool(shared_ptr<PBSession>, unsigned char*, int32_t)>;
extern PacketHandlerFunc GPacketHandler[UINT16_MAX];

enum : uint16_t {
	PKT_C_CONNECTION = 1000,
	PKT_S_LOGIN = 1001,
	PKT_C_LOGIN = 1002,
	PKT_S_ENTER_GAME = 1003,
	PKT_C_ENTER_GAME = 1004,
	PKT_C_CHAT = 1005,
	PKT_S_CHAT = 1006,
};

bool Handle_INVALID(shared_ptr<PBSession> sessionRef, unsigned char* buffer, int32_t len);
bool Handle_C_CONNECTION(shared_ptr<PBSession> sessionRef, PB::C_CONNECTION& pkt);
bool Handle_C_LOGIN(shared_ptr<PBSession> sessionRef, PB::C_LOGIN& pkt);
bool Handle_C_ENTER_GAME(shared_ptr<PBSession> sessionRef, PB::C_ENTER_GAME& pkt);
bool Handle_C_CHAT(shared_ptr<PBSession> sessionRef, PB::C_CHAT& pkt);

class ClientPacketHandler {
public:
	static void Init() {
		for (int32_t i = 0; i < UINT16_MAX; i++)
			GPacketHandler[i] = Handle_INVALID;
		GPacketHandler[PKT_C_CONNECTION] = [](shared_ptr<PBSession>sessionRef, unsigned char* buffer, int32_t len) { return HandlePacket<PB::C_CONNECTION>(Handle_C_CONNECTION, sessionRef, buffer, len); };
		GPacketHandler[PKT_C_LOGIN] = [](shared_ptr<PBSession>sessionRef, unsigned char* buffer, int32_t len) { return HandlePacket<PB::C_LOGIN>(Handle_C_LOGIN, sessionRef, buffer, len); };
		GPacketHandler[PKT_C_ENTER_GAME] = [](shared_ptr<PBSession>sessionRef, unsigned char* buffer, int32_t len) { return HandlePacket<PB::C_ENTER_GAME>(Handle_C_ENTER_GAME, sessionRef, buffer, len); };
		GPacketHandler[PKT_C_CHAT] = [](shared_ptr<PBSession>sessionRef, unsigned char* buffer, int32_t len) { return HandlePacket<PB::C_CHAT>(Handle_C_CHAT, sessionRef, buffer, len); };
	}

	static bool HandlePacket(shared_ptr<PBSession> sessionRef, unsigned char* buffer, int32_t len) {
		PacketHeader* header = reinterpret_cast<PacketHeader*>(buffer);
		return GPacketHandler[header->_id](sessionRef, buffer, len);
	}
	static shared_ptr<SendBuffer> MakeSendBufferRef(PB::S_LOGIN& pkt) { return MakeSendBufferRef(pkt, PKT_S_LOGIN); }
	static shared_ptr<SendBuffer> MakeSendBufferRef(PB::S_ENTER_GAME& pkt) { return MakeSendBufferRef(pkt, PKT_S_ENTER_GAME); }
	static shared_ptr<SendBuffer> MakeSendBufferRef(PB::S_CHAT& pkt) { return MakeSendBufferRef(pkt, PKT_S_CHAT); }

private:
	template<typename PBType, typename HandlerFunc>
	static bool HandlePacket(HandlerFunc func, shared_ptr<PBSession> sessionRef, unsigned char* buffer, int32_t len) {
		PBType pkt;
		if (pkt.ParseFromArray(buffer + sizeof(PacketHeader), len - sizeof(PacketHeader)) == false)
			return false;
		return func(sessionRef, pkt);
	}

	template<typename PBType>
	static shared_ptr<SendBuffer> MakeSendBufferRef(PBType& pkt, uint16_t pktId) {
		uint16_t dataSize = static_cast<uint16_t>(pkt.ByteSizeLong());
		uint16_t packetSize = dataSize + sizeof(PacketHeader);

		shared_ptr<SendBuffer> sendBufferRef = GSendBufferManager->Open(packetSize);
		PacketHeader* header = reinterpret_cast<PacketHeader*>(sendBufferRef->Buffer());
		header->_size = packetSize;
		header->_id = pktId;
		pkt.SerializeToArray(&header[1]/*(++header)*/, dataSize);
		sendBufferRef->Close(packetSize);

		return sendBufferRef;
	}
};