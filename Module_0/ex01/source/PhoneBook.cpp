#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	i = 0;
}

void	PhoneBook::add() {
	if(i == 8)
		contacts[0].addContact();
	else
	{
		if (!contacts[i].addContact())
			return ;
		i++;
	}
}

void	PhoneBook::search() {
	int			index = 0;
	std::string	contactSearch;

	while(index < i)
	{
		contacts[index].showContacts(index);
		index++;
	}
	if (!contacts[index].fillLine("Which contact you want to display? ", &contactSearch))
			return ;
	index = std::atoi(contactSearch.c_str());
	if (index < 0 || index >= i)
		cout << "Contact not available" << endl;
	else
		contacts[index].displayContact();
}

void	PhoneBook::addTestContact(std::string first, std::string last,
									std::string nick, std::string phone,
									std::string secret) {
	if(i == 8)
		contacts[0].addTestContact(first, last, nick, phone, secret);
	else
	{
		contacts[i].addTestContact(first, last, nick, phone, secret);
		i++;
	}
}
