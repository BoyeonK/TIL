#include "pch.h"
#include <iostream>
#include "serverSocketPractice1.h"
#include "serverSocketPractice2.h"
#include <thread>

using namespace std;

int main() {
	cout << "I'm Server" << endl;

	serverSocketPractice2();

	int a;
	cin >> a;
}