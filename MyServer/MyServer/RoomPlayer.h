#pragma once

class RoomPlayer {
public:
	uint64_t playerId = 0;
	string name;
	PB::PlayerType type = PB::PLAYER_TYPE_NONE;
	shared_ptr<PBSession> playerSession;
};

