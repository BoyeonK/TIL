#include "pch.h"
#include "SFunctor1.h"
#include "ServiceWithIocp_Server.h"
#include "Service.h"
#include "ServerPacketHandler.h"
#include "Room.h"
#include "RoomServerSession.h"
//server

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
	_room(roomRef)
	{}

private:
	shared_ptr<Room> _room;
};

shared_ptr<RoomServerSession> makeRS() {
	return make_shared<RoomServerSession>();
}

void SFunctor1() {
	ServerPacketHandler::Init();

	shared_ptr<RoomServerService> RS = make_shared<RoomServerService>(
		make_shared<CPCore>(),
		NetAddress(L"127.0.0.1", 7777),
		makeRS,
		100,
		make_shared<Room>()
	);
}
