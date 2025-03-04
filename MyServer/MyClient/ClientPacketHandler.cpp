#include "pch.h"
#include "ClientPacketHandler.h"

PacketHandlerFunc GPacketHandler[UINT16_MAX];

bool Handle_INVALID(shared_ptr<PBSession> sessionRef, unsigned char* buffer, int32_t len) {
	return false;
}

bool Handle_C_CONNECTION(shared_ptr<PBSession> sessionRef, PB::C_CONNECTION& pkt) {
	cout << "Connected 완료 응답을 받았다!" << endl;
	if (pkt.isvalid()) {
		//지금은 하드코딩해서 넣어줬지만 input으로 바꿔 줄 수도 있을 것 같다.
		PB::S_LOGIN S_LOGIN_PKT;
		string myID = u8"tetepiti149";
		string myPassword = u8"q1w2e3r4!@";
		S_LOGIN_PKT.set_id(myID);
		S_LOGIN_PKT.set_password(myPassword);
		shared_ptr<SendBuffer>loginRequestPKT = ClientPacketHandler::MakeSendBufferRef(S_LOGIN_PKT);
		sessionRef->Send(loginRequestPKT);
		cout << "tetepiti149의 로그인 요청 보냄" << endl;
		return true;
	}
	else {
		cout << "Server로부터 연결 요청이 거절" << endl;
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
		//새 캐릭터 생성 유도
	}

	//캐릭터 선택
	static atomic<uint64_t> a = 0;
	PB::Character selectedCharacter = pkt.characters().Get(a%3);
	//a.fetch_add(1);

	//선택한 캐릭터로 ENTER 요청
	PB::S_ENTER_GAME S_ENTER_GAME_PKT;
	S_ENTER_GAME_PKT.set_charid(selectedCharacter.charid());
	S_ENTER_GAME_PKT.set_token(pkt.token());

	//요청 발사
	shared_ptr<SendBuffer> enterRequestPKT = ClientPacketHandler::MakeSendBufferRef(S_ENTER_GAME_PKT);
	sessionRef->Send(enterRequestPKT);
	cout << "Room에 입장 요청을 보냈다!" << endl;
	return true;
}

bool Handle_C_ENTER_GAME(shared_ptr<PBSession> sessionRef, PB::C_ENTER_GAME& pkt) {
	if (pkt.isvalid() == true) {
		cout << "입장 요청이 성공했다는 응답을 받음" << endl;
		cout << "Player의 ID는 " << pkt.charid() << "번입니다." << endl;
	}
	else {
		cout << "입장 요청이 실패했다는 응답을 받음" << endl;
	}
	return true;
}

bool Handle_C_CHAT(shared_ptr<PBSession> sessionRef, PB::C_CHAT& pkt) {
	cout << "got a message : " << pkt.msg() << endl;
	return false;
}
