#include <iostream>
#include <fstream>
#include <string>

void	replace(std::string line, std::string fileName, std::string replaceString, std::string replacement) {
	size_t pos = 0;
	std::ofstream fileReplace;

	fileName += ".replace";
	fileReplace.open(fileName.c_str(), std::ios::out);
	if (!fileReplace.is_open()) {
		std::cerr << "Error creating output file\n";
		return ;
	}
	while ((pos = line.find(replaceString, pos)) != std::string::npos) {
		line.erase(pos, replaceString.length());
		line.insert(pos, replacement);
		pos += replacement.length();
	}
	fileReplace << line;
	fileReplace.close();
}

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "Incorrect input\n./sed_for_loser <filename> <string1> <string2>" << std::endl;
		return (1);
	}
	std::string line;
	std::string fileLine;
	std::ifstream file;
	file.open(argv[1], std::ios::in);
	if (file.fail()) {
		std::cerr << "Error opening file\n";
		return 1;
	}
	while (getline(file, fileLine))
		line += fileLine + "\n";
	file.close();
	replace(line, argv[1], argv[2], argv[3]);
	return (0);
}
