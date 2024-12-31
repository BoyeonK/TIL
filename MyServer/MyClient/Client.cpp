#include "pch.h"
#include <iostream>
#include "example.pb.h"
#include <thread>
#include "clientSocketPractice1.h"

using namespace std;

int main() {
	cout << "I'm Client" << endl;
	example::Person pkt;

	this_thread::sleep_for(1s);

	clientServerPractice1();
}