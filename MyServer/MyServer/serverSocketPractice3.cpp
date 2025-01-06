#include "pch.h"
#include "serverSocketPractice3.h"
#include "SocketUtils.h"
#include "Listener.h"

void serverSocketPractice3() {
	shared_ptr<Listener>listener = make_shared<Listener>(NetAddress(L"127.0.0.1", 7777));
}
