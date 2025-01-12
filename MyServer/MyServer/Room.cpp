#include "pch.h"
#include "Room.h"

void Room::Enter(shared_ptr<RoomPlayer> playerRef) {
	WRITE_RWLOCK;
	_players[playerRef->_playerId] = playerRef;
}

void Room::Leave(shared_ptr<RoomPlayer> playerRef) {
	WRITE_RWLOCK;
	_players.erase(playerRef->_playerId);
}

void Room::BroadCast(shared_ptr<SendBuffer> sendBufferRef) {
	WRITE_RWLOCK;
	for (auto& p : _players) 
		p.second->_playerSession->Send(sendBufferRef);
}
