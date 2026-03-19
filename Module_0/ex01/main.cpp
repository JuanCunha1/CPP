#include "PhoneBook.hpp"

int main(void)
{
	std::string	input;
	PhoneBook	phone;

	std::cout << "What you want to do with your phonebook? "
			  << " (ADD, SEARCH, EXIT) " << std::endl;
	std::cout << "phonebook > ";
	while(std::getline(std::cin, input) && input != "EXIT")
	{
		if (input == "ADD")
			phone.add();
		else if (input == "SEARCH")
			phone.search();
		else
			std::cout << "Invalid command. Try again." << std::endl;
		std::cout << "phonebook > ";
	}
	return (0);
}
/*
int main(void)
{
	PhoneBook	pb;
	std::string	input;

	pb.addTestContact("1", "A", "A", "111", "S1");
	pb.addTestContact("2", "B", "B", "222", "S2");
	pb.addTestContact("3", "C", "C", "333", "S3");
	pb.addTestContact("4", "D", "D", "444", "S4");
	pb.addTestContact("5", "E", "E", "555", "S5");
	pb.addTestContact("6", "F", "F", "666", "S6");
	pb.addTestContact("7", "G", "G", "777", "S7");
	pb.addTestContact("8", "H", "H", "888", "S8");
	pb.addTestContact("9", "I", "I", "999", "S9");

	std::cout << "Welcome to your phonebook!" << std::endl;
	while(1)
	{
		std::cout << "What you want to do with your phonebook? "
				  << " (ADD, SEARCH, EXIT) ";
		std::getline(std::cin, input);
		if (input == "ADD")
			pb.add();
		else if (input == "SEARCH")
			pb.search();
		else if (input == "EXIT")
			break ;
		else
			std::cout << "Invalid command. Try again." << std::endl;
	}
	return (0);
}
*/
