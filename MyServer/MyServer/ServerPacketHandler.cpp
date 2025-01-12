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
	//��ȿ�� �˻�, ���� ������Ʈ��� ������ �������� ���� �� ���̴�.
	string ID;
	string password;
	ID = pkt.id();
	password = pkt.password();

	PB::C_LOGIN C_LOGIN_PKT;
	string token = "";

	bool invalidID = false; //��ȿ�� ���̵� �ƴ� ���
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

	//DB�� �ִٸ�, ���� �̷� �������� DB�� ����Ǿ� ���� ��.
	//���Ƿ� ����, ����, �ü��� 1ĳ���� Ű���ٰ� �����ϰ� �ڵ� �ۼ�
	string Cname;
	PB::Character* knight = C_LOGIN_PKT.add_characters();
	PB::Character* mage = C_LOGIN_PKT.add_characters();
	PB::Character* archer = C_LOGIN_PKT.add_characters();
	knight->set_charid(PlayerNum + 1);
	mage->set_charid(PlayerNum + 2);
	archer->set_charid(PlayerNum + 3);

	Cname = "Ÿ���Ŀ�����";
	knight->set_charname(Cname);
	Cname = "Ÿ���Ŀ�����";
	mage->set_charname(Cname);
	Cname = "Ÿ���Ŀ��ü�";
	archer->set_charname(Cname);
	PlayerNum.fetch_add(4);

	knight->set_charclass(PB::PLAYER_TYPE_KNIGHT);
	mage->set_charclass(PB::PLAYER_TYPE_MAGE);
	archer->set_charclass(PB::PLAYER_TYPE_ARCHER);

	shared_ptr<SendBuffer>loginResponsePKT = ServerPacketHandler::MakeSendBufferRef(C_LOGIN_PKT);
	sessionRef->Send(loginResponsePKT);
	return true;
}

bool Handle_S_ENTER_GAME(shared_ptr<PBSession> sessionRef, PB::S_ENTER_GAME& pkt) {
	string token = pkt.token();
	uint64_t requestID = pkt.charid();

	PB::C_ENTER_GAME C_ENTER_GAME_PKT;
	C_ENTER_GAME_PKT.set_charid(requestID);
	C_ENTER_GAME_PKT.set_isvalid(true);

	shared_ptr<SendBuffer> enterResponsePKT = ServerPacketHandler::MakeSendBufferRef(C_ENTER_GAME_PKT);
	sessionRef->Send(enterResponsePKT);
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
