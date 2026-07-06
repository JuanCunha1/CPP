#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {

	if (argc == 1)
		return (std::cout << "Please provide numbers to be sorted." << std::endl, 1);
	try
	{
		PmergeMe(argc, argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
