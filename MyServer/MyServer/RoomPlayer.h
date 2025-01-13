#pragma once
#include "PB.pb.h"

class RoomPlayer {
public:
	shared_ptr<PBSession> GetSession() { return _playerSession.lock(); }
	void SetSession(shared_ptr<PBSession> sessionRef) { 
		_playerSession = sessionRef; 
		if (_playerSession.lock() == nullptr) {
			cout << "뭔가 잘못됬스우" << endl;
		}
	}

	uint64_t _playerId = 0;
	string _name;
	PB::PlayerType _type = PB::PLAYER_TYPE_NONE;

private:
	weak_ptr<PBSession> _playerSession;
};

