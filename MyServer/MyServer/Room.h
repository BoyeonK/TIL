#pragma once
#include "RoomPlayer.h"
#include <map>

class Room {
public:
	void Enter(shared_ptr<RoomPlayer> playerRef);
	void Leave(shared_ptr<RoomPlayer> playerRef);
	void BroadCast(shared_ptr<SendBuffer> sendBufferRef);

private:
	USE_RWLOCK;
	map<uint64_t, shared_ptr<RoomPlayer>> _players;
};

