#pragma once
#include "Room.h"

class RoomServerService : public ServerService {
public:
	RoomServerService(
		shared_ptr<CPCore>CPCoreRef,
		NetAddress address,
		SessionFactory sessionFactory,
		uint32_t maxSessionCount,
		shared_ptr<Room> roomRef
	)
		:
		ServerService(
			CPCoreRef,
			address,
			sessionFactory,
			maxSessionCount
		),
		_roomRef(roomRef)
	{}
	
	shared_ptr<Room> _roomRef;
	//몰라 그냥 public으로 열어 ㅋㅋ
};

