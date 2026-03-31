#include "Harl.hpp"
#include <string>

void Harl::debug() {
	std::cout << "[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n" << std::endl;
}

void Harl::info() {
	std::cout << "[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put"
				 "enough bacon in my burger! If you did, I wouldn’t be asking for more!\n" << std::endl;
}

void Harl::warning() {
	std::cout << "[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for "
	"years, whereas you started working here just last month.\n" << std::endl;
}

void Harl::error() {
	std::cout << "[ ERROR ]\n";
	std::cout << "This is unacceptable! I want to speak to the manager now.\n" << std::endl;
}

void Harl::complain( std::string str ) {
	void (Harl::*func_ptr[4])() = {&Harl::debug, &Harl::info, &Harl::warning,
                                   &Harl::error};
	std::string level(str);
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i;
	for (i = 0; i <= 3; i++) {
		if (level == levels[i])
			break ;
    }
	switch (i) {
	 	default:
            std::cout << "[ Probably complaining about insignificant problems ]\n";
            break ;
        case 0:
            (this->*func_ptr[0])();
            // fall through
        case 1:
            (this->*func_ptr[1])();
            // fall through
        case 2:
            (this->*func_ptr[2])();
            // fall through
        case 3:
            (this->*func_ptr[3])();
            break;

    }
}
