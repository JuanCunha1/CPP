#include "Contact.hpp"

Contact Contact::add_contact(void)
{
	Contact contact;

	std::cout << "Please input to contact" << std::endl;
	std::cout << "Insert contact Name: ";
	std::cin >> contact.Name;
	std::cout << "Insert contact last name: ";
	std::cin >> contact.LastName;
	std::cout << "Insert contact nickname: ";
	std::cin >> contact.Nickname;
	std::cout << "Insert contact phone number: ";
	std::cin >> contact.PhoneNumber;
	std::cout << "Insert contact darkest secret: ";
	std::cin >> contact.DarkestSecret;
	return (contact);
}

std::string Contact::format_field(std::string str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void	Contact::show_contacts(int index)
{
	std::cout << std::setw(10) << index << "|"
				<< std::setw(10) << format_field(Name) << "|"
				<< std::setw(10) << format_field(LastName) << "|"
				<< std::setw(10) << format_field(Nickname)
				<< std::endl;
}

void	Contact::display_contact(void)
{
	std::cout << "Name: " << Name << std::endl;
	std::cout << "Last name: " << LastName << std::endl;
	std::cout << "Nickname: " << Nickname << std::endl;
	std::cout << "Phone number: " << PhoneNumber << std::endl;
	std::cout << "Darkest secret: " <<DarkestSecret << std::endl;
}
