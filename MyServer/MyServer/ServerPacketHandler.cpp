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
	//��ȿ�� �˻�, ���� ������Ʈ��� ������ �������� ���� �� ���̴�.
	cout << "�α��� ��û ��Ŷ�� �޾Ҵ�!" << endl;
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
	string name1, name2, name3;
	PB::Character* knight = C_LOGIN_PKT.add_characters();
	PB::Character* mage = C_LOGIN_PKT.add_characters();
	PB::Character* archer = C_LOGIN_PKT.add_characters();
	knight->set_charid(PlayerNum + 1);
	mage->set_charid(PlayerNum + 2);
	archer->set_charid(PlayerNum + 3);

	name1 = u8"Ÿ���Ŀ�����";
	knight->set_charname(name1);
	name2 = u8"Ÿ���Ŀ�����";
	mage->set_charname(name2);
	name3 = u8"Ÿ���Ŀ��ü�";
	archer->set_charname(name3);
	PlayerNum.fetch_add(4);

	knight->set_charclass(PB::PLAYER_TYPE_KNIGHT);
	mage->set_charclass(PB::PLAYER_TYPE_MAGE);
	archer->set_charclass(PB::PLAYER_TYPE_ARCHER);

	shared_ptr<SendBuffer>loginResponsePKT = ServerPacketHandler::MakeSendBufferRef(C_LOGIN_PKT);
	sessionRef->Send(loginResponsePKT);
	cout << "�α��ε� ������ ��밡���� ĳ���͵� ������ ���´�!" << endl;
	return true;
}

bool Handle_S_ENTER_GAME(shared_ptr<PBSession> sessionRef, PB::S_ENTER_GAME& pkt) {
	cout << "���� ��û�� �޾Ҵ�!" << endl;
	string token = pkt.token();
	uint64_t requestID = pkt.charid();

	PB::C_ENTER_GAME C_ENTER_GAME_PKT;

	shared_ptr<Service> serviceRef = sessionRef->GetService();
	shared_ptr<RoomServerService> roomServiceRef = dynamic_pointer_cast<RoomServerService>(serviceRef);
	if (roomServiceRef == nullptr) {
		//�ش� service�� Room�� �������� �ʴ� ��� ���� ��û ����
		C_ENTER_GAME_PKT.set_isvalid(false);
		cout << "���� ��û ����!" << endl;
	}
	else {
		shared_ptr<RoomPlayer> playerRef = make_shared<RoomPlayer>();
		playerRef->_playerId = requestID;
		//�������, ID�� �ش��ϴ� �������� DB���� �������°��� �´� �׸��ϰ� ����.
		playerRef->_name = "����player��";
		playerRef->_type = PB::PLAYER_TYPE_KNIGHT;
		playerRef->_playerSession = sessionRef;
		roomServiceRef->_roomRef->Enter(playerRef);
		C_ENTER_GAME_PKT.set_charid(requestID);
		C_ENTER_GAME_PKT.set_isvalid(true);	
		cout << "���� ��û ����" << endl;
	}

	shared_ptr<SendBuffer> enterResponsePKT = ServerPacketHandler::MakeSendBufferRef(C_ENTER_GAME_PKT);
	sessionRef->Send(enterResponsePKT);
	cout << "�����û�� ���� ������ ���´�." << endl;
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
