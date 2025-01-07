#include "pch.h"
#include <iostream>
#include "example.pb.h"
#include <thread>
//#include "clientSocketPractice1.h"
#include "ServiceWithIocp_Client.h"

using namespace std;

int main() {
	cout << "I'm Client" << endl;
	example::Person pkt;

	ServiceWithIocp_Client();
}