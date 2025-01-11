#include "pch.h"
#include "ClientPacketHandler.h"

PacketHandlerFunc GPacketHandler[UINT16_MAX];

bool Handle_INVALID(shared_ptr<PBSession> sessionRef, unsigned char* buffer, int32_t len) {
	return false;
}

bool Handle_C_CONNECTION(shared_ptr<PBSession> sessionRef, PB::C_CONNECTION& pkt) {
	if (pkt.isvalid()) {
		//������ �ϵ��ڵ��ؼ� �־������� input���� �ٲ� �� ���� ���� �� ����.
		//Unicode�� ���ڵ��ϱ� �������� ������ �׳� string�� ������ش�.
		PB::S_LOGIN S_LOGIN_PKT;
		string myID = "tetepiti149";
		string myPassword = "q1w2e3r4!@";
		S_LOGIN_PKT.set_id(myID);
		S_LOGIN_PKT.set_password(myPassword);
		shared_ptr<SendBuffer>loginRequestPKT = ClientPacketHandler::MakeSendBufferRef(S_LOGIN_PKT);
		sessionRef->Send(loginRequestPKT);
		return true;
	}
	else {
		cout << "Server�κ��� ���� ��û�� ����" << endl;
		//sessionRef->Disconnect();
		return false;
	}
}

bool Handle_C_LOGIN(shared_ptr<PBSession> sessionRef, PB::C_LOGIN& pkt) {
	if (pkt.isvalid() == false) {
		cout << "invaild ID or password" << endl;
		return true;
	}
	if (pkt.characters().size() == 0) {
		//�� ĳ���� ���� ����
	}

	//ĳ���� ����
	static atomic<uint64_t> a = 0;
	PB::Character selectedCharacter = pkt.characters().Get(a%3);
	a.fetch_add(1);

	//������ ĳ���ͷ� ENTER ��û
	PB::S_ENTER_GAME S_ENTER_GAME_PKT;
	S_ENTER_GAME_PKT.set_charid(selectedCharacter.charid());
	S_ENTER_GAME_PKT.set_token(pkt.token());

	//��û �߻�
	shared_ptr<SendBuffer> enterRequestPKT = ClientPacketHandler::MakeSendBufferRef(S_ENTER_GAME_PKT);
	sessionRef->Send(enterRequestPKT);
	return true;
}

bool Handle_C_ENTER_GAME(shared_ptr<PBSession> sessionRef, PB::C_ENTER_GAME& pkt) {
	return false;
}

bool Handle_C_CHAT(shared_ptr<PBSession> sessionRef, PB::C_CHAT& pkt) {
	cout << "got a message : " << pkt.msg() << endl;
	return false;
}
