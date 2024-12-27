#include <iostream>
#include <string>

int main() {
	std::string asdf;
	int i=0;
	while (std::cin >> asdf) i++;
	std::cout << i;
}