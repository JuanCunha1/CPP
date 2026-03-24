#include <iostream>
#include <fstream>

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "Not enough arguments" << std::endl;
		return (1);
	}
	std::string line;
	std::ifstream file_replace;
	std::ofstream file;
	file.open(argv[1], std::ios::in);
	if (file.fail()) {
		std::cerr << "Error opening file\n";
		return 1;
	}
	std::string file_replace_name = argv[1];
	file_replace_name += ".replace";
	file_replace.open(file_replace_name, std::ios::out);
	if (!file_replace.is_open()) {
        std::cerr << "Error creating output file\n";
        return 1;
    }
	while ()

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