#include "pch.h"
#include "ServerPacketHandler.h"
#include "RoomServerService.h"
#include "Room.h"

PacketHandlerFunc GPacketHandler[UINT16_MAX];

bool Handle_INVALID(shared_ptr<PBSession> sessionRef, unsigned char* buffer, int32_t len) {
#ifdef _DEBUG
	cout << "Something goes wrong, Client sent invalid packet" << endl;
#endif
	return false;
}

bool Handle_S_LOGIN(shared_ptr<PBSession> sessionRef, PB::S_LOGIN& pkt) {
	//유효성 검사, 실제 프로젝트라면 별도의 서버에서 진행 될 것이다.
	cout << "로그인 요청 패킷을 받았다!" << endl;
	string ID;
	string password;
	ID = pkt.id();
	password = pkt.password();

	PB::C_LOGIN C_LOGIN_PKT;
	string token = "";

	bool invalidID = false; //유효한 아이디가 아닌 경우
	if (invalidID) {
		C_LOGIN_PKT.set_isvalid(false);
		C_LOGIN_PKT.set_token(token);
		shared_ptr<SendBuffer>loginResponsePKT = ServerPacketHandler::MakeSendBufferRef(C_LOGIN_PKT);
		sessionRef->Send(loginResponsePKT);
		return true;
	}
	C_LOGIN_PKT.set_isvalid(true);
	C_LOGIN_PKT.set_token(token);

	static atomic<uint64_t> PlayerNum = 0;

	//DB가 있다면, 원래 이런 정보들은 DB에 저장되어 있을 것.
	//임의로 전사, 법사, 궁수를 1캐릭씩 키웠다고 가정하고 코드 작성
	string name1, name2, name3;
	PB::Character* knight = C_LOGIN_PKT.add_characters();
	PB::Character* mage = C_LOGIN_PKT.add_characters();
	PB::Character* archer = C_LOGIN_PKT.add_characters();
	knight->set_charid(PlayerNum + 1);
	mage->set_charid(PlayerNum + 2);
	archer->set_charid(PlayerNum + 3);

	name1 = u8"타락파워전사";
	knight->set_charname(name1);
	name2 = u8"타락파워법사";
	mage->set_charname(name2);
	name3 = u8"타락파워궁수";
	archer->set_charname(name3);
	PlayerNum.fetch_add(4);

	knight->set_charclass(PB::PLAYER_TYPE_KNIGHT);
	mage->set_charclass(PB::PLAYER_TYPE_MAGE);
	archer->set_charclass(PB::PLAYER_TYPE_ARCHER);

	shared_ptr<SendBuffer>loginResponsePKT = ServerPacketHandler::MakeSendBufferRef(C_LOGIN_PKT);
	sessionRef->Send(loginResponsePKT);
	cout << "로그인된 계정의 사용가능한 캐릭터들 정보를 보냈다!" << endl;
	return true;
}

bool Handle_S_ENTER_GAME(shared_ptr<PBSession> sessionRef, PB::S_ENTER_GAME& pkt) {
	cout << "입장 요청을 받았다!" << endl;
	string token = pkt.token();
	uint64_t requestID = pkt.charid();

	PB::C_ENTER_GAME C_ENTER_GAME_PKT;

	shared_ptr<Service> serviceRef = sessionRef->GetService();
	shared_ptr<RoomServerService> roomServiceRef = dynamic_pointer_cast<RoomServerService>(serviceRef);
	if (roomServiceRef == nullptr) {
		//해당 service가 Room을 지원하지 않는 경우 입장 요청 거절
		C_ENTER_GAME_PKT.set_isvalid(false);
		cout << "입장 요청 거절!" << endl;
	}
	else {
		shared_ptr<RoomPlayer> playerRef = make_shared<RoomPlayer>();
		playerRef->_playerId = requestID;
		//원래라면, ID에 해당하는 정보들을 DB에서 가져오는것이 맞는 그림일것 같다.
		playerRef->_name = "낙인player좌";
		playerRef->_type = PB::PLAYER_TYPE_KNIGHT;
		playerRef->_playerSession = sessionRef;
		roomServiceRef->_roomRef->Enter(playerRef);
		C_ENTER_GAME_PKT.set_charid(requestID);
		C_ENTER_GAME_PKT.set_isvalid(true);	
		cout << "입장 요청 성공" << endl;
	}

	shared_ptr<SendBuffer> enterResponsePKT = ServerPacketHandler::MakeSendBufferRef(C_ENTER_GAME_PKT);
	sessionRef->Send(enterResponsePKT);
	cout << "입장요청에 대한 응답을 보냈다." << endl;
	return true;
}

bool Handle_S_CHAT(shared_ptr<PBSession> sessionRef, PB::S_CHAT& pkt) {
	cout << "Chat Message from " << pkt.playerid() << " : " << pkt.msg() << endl;
	PB::C_CHAT c_chat_pkt;
	string c_msg = "chat request from " + to_string(pkt.playerid()) + "is succeed!";
	c_chat_pkt.set_msg(c_msg);
	shared_ptr<SendBuffer> sendBufferRef = ServerPacketHandler::MakeSendBufferRef(c_chat_pkt);
	sessionRef->Send(sendBufferRef);
	return true;
}
