#include <iostream>
#include <fstream>
#include <string>

void	replace(std::ifstream &file, std::string fileName, std::string toFind, std::string toReplace) {
	if (toFind.empty())
		return;
	std::ofstream outfile((fileName + ".replace").c_str());
	if (!outfile.is_open()) {
		std::cout << "Error creating output file\n";
		return;
	}
	std::string line;
	while (getline(file, line)) {
		size_t pos = 0;
		while ((pos = line.find(toFind, pos)) != std::string::npos) {
			line.erase(pos, toFind.length());
			line.insert(pos, toReplace);
			pos += toReplace.length();
		}
		outfile << line << std::endl;
	}
	outfile.close();
}

int main(int argc, char **argv) {
	if (argc != 4) {
		std::cout << "Incorrect input\n./sed_for_loser <filename> <string1> <string2>" << std::endl;
		return (1);
	}
	std::string fileLine;
	std::ifstream file(argv[1]);
	if (!file.is_open()) {
		std::cout << "Error opening file\n";
		return 1;
	}
	replace(file, argv[1], argv[2], argv[3]);
	file.close();
	return (0);
}
