#include "BitcoinExchange.hpp"


int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " <data_file>" << std::endl;
		return 1;
	}
	std::ifstream file(argv[1]);
	if (!file.is_open())
		return (std::cerr << "Couldn't open the file " << argv[1] << std::endl, 1);
	if (file.peek() == std::ifstream::traits_type::eof())
		return (std::cerr << "No content on the file " << argv[1] << std::endl, 1);
	try {
		BitcoinExchange btc(file);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	file.close();
	return 0;
}
