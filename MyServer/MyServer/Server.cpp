#include "pch.h"
#include <iostream>
#include "MyLibraries.h"
#include "serverSocketPractice1.h"
#include <thread>

using namespace std;

int main() {
	cout << "I'm Server" << endl;
	HelloWorld();

	serverSocketPractice1();

	int a;
	cin >> a;
}