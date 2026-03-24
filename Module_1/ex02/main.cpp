#include <iostream>

int main(void) {
	std::string brainString = "HI THIS IS BRAIN";
	std::string *stringPTR = &brainString;
	std::string &stringREF = brainString;

	std::cout << &brainString << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << brainString << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;

	return (0);
}