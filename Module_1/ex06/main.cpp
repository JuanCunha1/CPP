#include "Harl.hpp"

int main(int argc, char **argv) {
    Harl testclass;

    if (argc != 2) {
    	std::cout << "Set log level" << std::endl;
    	return 1;
    }
    testclass.complain(argv[1]);
}
