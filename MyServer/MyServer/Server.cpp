#include "pch.h"
#include <iostream>
#include "serverSocketPractice1.h"
#include "serverSocketPractice2.h"
#include <thread>

using namespace std;

int main() {
	cout << "I'm Server" << endl;

	serverSocketPractice2();
	//shared_ptr<Listener>listener = make_shared<Listener>(NetAddress(L"127.0.0.1", 7777));

	int a;
	cin >> a;
}