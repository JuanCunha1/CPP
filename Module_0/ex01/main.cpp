#include "PhoneBook.hpp"

int main(void)
{
	int			running = 1;
	std::string	input;
	PhoneBook	phone;
	int			contactSearch;

	std::cout << "Welcome to your phonebook!" << std::endl;
	while(running)
	{
		std::cout << "What you want to do with your phonebook? "
				  << " (ADD, SEARCH, EXIT) ";
		std::getline(std::cin, input);
		if (input == "ADD")
			phone.add();
		else if (input == "SEARCH")
		{
			phone.search();
			std::cout << "Which contact you want to display? ";
			std::getline(std::cin, contactSearch);
			contactSearch = std::atoi(line.c_str());
			phone.display(contactSearch);
		}
		else if (input == "EXIT")
			running = 0;
	}
	return (0);
}
