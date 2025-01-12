#include "pch.h"
#include <iostream>
#include <thread>
//#include "clientSocketPractice1.h"
#include "ServiceWithIocp_Client.h"
#include "Functor1.h"

using namespace std;

int main() {
	cout << "I'm Client" << endl;

	//ServiceWithIocp_Client();
	Functor1();
}