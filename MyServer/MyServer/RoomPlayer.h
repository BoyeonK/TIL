#pragma once
#include "PB.pb.h"

class RoomPlayer {
public:
	uint64_t _playerId = 0;
	string _name;
	PB::PlayerType _type = PB::PLAYER_TYPE_NONE;
	shared_ptr<PBSession> _playerSession;
};

