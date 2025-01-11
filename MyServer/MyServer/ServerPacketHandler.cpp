#include "pch.h"
#include "ServerPacketHandler.h"

PacketHandlerFunc GPacketHandler[UINT16_MAX];

bool Handle_INVALID(shared_ptr<PBSession> sessionRef, unsigned char* buffer, int32_t len) {
#ifdef _DEBUG
	cout << "Something goes wrong, Client sent invalid packet" << endl;
#endif
	return false;
}

bool Handle_S_LOGIN(shared_ptr<PBSession> sessionRef, PB::S_LOGIN& pkt) {
	//유효성 검사, 실제 프로젝트라면 별도의 서버에서 진행 될 것이다.
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

	static atomic<uint64_t> PlayerNum = 1;

	//DB가 있다면, 원래 이런 정보들은 DB에 저장되어 있을 것.
	string Cname;
	PB::Character* knight = C_LOGIN_PKT.add_characters();
	PB::Character* mage = C_LOGIN_PKT.add_characters();
	PB::Character* archer = C_LOGIN_PKT.add_characters();
	knight->set_charid(PlayerNum);
	mage->set_charid(PlayerNum + 1);
	archer->set_charid(PlayerNum + 2);

	Cname = "타락파워전사";
	knight->set_charname(Cname);
	Cname = "타락파워법사";
	mage->set_charname(Cname);
	Cname = "타락파워궁수";
	archer->set_charname(Cname);
	PlayerNum.fetch_add(3);

	knight->set_charclass(PB::PLAYER_TYPE_KNIGHT);
	mage->set_charclass(PB::PLAYER_TYPE_MAGE);
	archer->set_charclass(PB::PLAYER_TYPE_ARCHER);

	shared_ptr<SendBuffer>loginResponsePKT = ServerPacketHandler::MakeSendBufferRef(C_LOGIN_PKT);
	sessionRef->Send(loginResponsePKT);
	return true;
}

bool Handle_S_ENTER_GAME(shared_ptr<PBSession> sessionRef, PB::S_ENTER_GAME& pkt) {
	return false;
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
