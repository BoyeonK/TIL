#include "pch.h"
#include <iostream>
#include "serverSocketPractice1.h"
#include "serverSocketPractice2.h"
#include "serverSocketPractice3.h"
#include <thread>

using namespace std;

int main() {
	SocketUtils::Init();
	cout << "I'm Server" << endl;

	serverSocketPractice3();

	int a;
	cin >> a;
}