#include "pch.h"
#include "Room.h"

void Room::Enter(shared_ptr<RoomPlayer> playerRef) {
	WRITE_RWLOCK;
	_players[playerRef->_playerId] = playerRef;
	cout << playerRef->_playerId << "번의 입장처리 완료" << endl;
}

void Room::Leave(shared_ptr<RoomPlayer> playerRef) {
	WRITE_RWLOCK;
	cout << playerRef->_playerId << "번의 퇴장처리 시도" << endl;
	_players.erase(playerRef->_playerId);
}

void Room::BroadCast(shared_ptr<SendBuffer> sendBufferRef) {
	WRITE_RWLOCK;
	for (auto& p : _players) 
		p.second->GetSession()->Send(sendBufferRef);
}
