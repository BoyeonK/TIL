#include "pch.h"
#include <iostream>
#include "example.pb.h"
#include <thread>
#include "clientSocketPractice1.h"
#include "clientSocketPractice4.h"

using namespace std;

int main() {
	cout << "I'm Client" << endl;
	example::Person pkt;

	clientSocketPractice4();
}