#include "BitcoinExchange.hpp"


int main(int argc, char **argv) {
	if (argc != 2) {
		std::cout << "Usage: " << argv[0] << " <data_file>" << std::endl;
		return 1;
	}
	std::ifstream file(argv[1]);
	if (!file.is_open())
		return (std::cout << "Couldn't open the file " << argv[1] << std::endl, 0);
	if (file.peek() == std::ifstream::traits_type::eof())
		return (std::cout << "No content on the file " << argv[1] << std::endl, 0);
	BitcoinExchange btc(argv[1]);
	file.close();
	return 0;
}
