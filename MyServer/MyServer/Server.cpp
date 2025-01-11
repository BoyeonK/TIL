#include "pch.h"
#include <iostream>
#include <thread>
//#include "serverSocketPractice1.h"
//#include "serverSocketPractice2.h"
#include "ServiceWithIocp_Server.h"


using namespace std;

int main() {
	cout << "I'm Server" << endl;

	ServiceWithIocp_Server();

}