#include "PhoneBook.hpp"

void	PhoneBook::add()
{
	Contact contact;
	if(i == 8)
		contacts[0] = contact.add_contact();
	else
	{
		contacts[i] = contact.add_contact();
		i++;
	}
}

void	PhoneBook::search()
{
	int index = 0;
	std::cout << std::setw(10);
	while(index < i)
	{
		contacts[index].show_contacts(index);
		index++;
	}
}

void	PhoneBook::display(int index)
{
	if (index < 0 || index >= i)
	{
		std::cout << "Contact not available" << std::endl;
		return ;
	}
	contacts[index].display_contact();
}
