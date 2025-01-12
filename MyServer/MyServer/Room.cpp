#include "pch.h"
#include "Room.h"

void Room::Enter(shared_ptr<RoomPlayer> playerRef) {
	WRITE_RWLOCK;
	cout << "ENTER" << endl;
}

void Room::Leave(shared_ptr<RoomPlayer> playerRef) {
	WRITE_RWLOCK;

}

void Room::BroadCast(shared_ptr<SendBuffer> SendBufferRef) {
	WRITE_RWLOCK;

}
