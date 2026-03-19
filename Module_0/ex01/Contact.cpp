#include "Contact.hpp"

static void	fillLine(std::string out, std::string *in)
{
	std::string tmp;

	std::cout << out;
	while (std::getline(std::cin, tmp) && !tmp[0])
	{
		std::cout << "No empty fields!" << std::endl << out;
	}
	*in = tmp;
}

static int         isPhoneNumber(std::string pn)
{
    int	i;

    if ((!std::isdigit(pn[0]) && pn[0] != '+') || (pn[0] == '+' && !std::isdigit(pn[1])))
    {
        std::cout << "Please enter a valid number (no brackets, only '+' and digits allowed)" << std::endl;
        return (false);
    }
    for (i = 1; pn[i]; i++)
    {
        if (!std::isdigit(pn[i]))
        {
            std::cout << "Please enter a valid number (no brackets, only '+' and digits allowed)" << std::endl;
            return (false);
        }
    }
    if ((pn[0] == '+' && i < 4) || i < 3)
    {
        std::cout << "Please enter a valid number (min 3 digits)" << std::endl;
        return (false);
    }
    return (true);
}

Contact Contact::addContact(void)
{
	Contact		contact;
	std::string tmp_num;

	fillLine("Firstname: ", &Name);
    fillLine("Lastname: ", &LastName);
    fillLine("Nickname: ", &Nickname);
    fillLine("Number: ", &tmp_num);
    while (!isPhoneNumber(tmp_num))
        fillLine("Number: ", &tmp_num);
    PhoneNumber = tmp_num;
    fillLine("Darkest secret: ", &DarkestSecret);
	return (contact);
}

std::string Contact::format_field(std::string str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void	Contact::showContacts(int index)
{
	std::cout << std::setw(10) << index << "|"
				<< std::setw(10) << format_field(Name) << "|"
				<< std::setw(10) << format_field(LastName) << "|"
				<< std::setw(10) << format_field(Nickname)
				<< std::endl;
}

void	Contact::displayContact(void)
{
	std::cout << "Name: " << Name << std::endl;
	std::cout << "Last name: " << LastName << std::endl;
	std::cout << "Nickname: " << Nickname << std::endl;
	std::cout << "Phone number: " << PhoneNumber << std::endl;
	std::cout << "Darkest secret: " <<DarkestSecret << std::endl;
}

void	Contact::addTestContact(std::string first, std::string last,
                               std::string nick, std::string phone,
                               std::string secret)
{
	Name = first;
	LastName = last;
	Nickname = nick;
	PhoneNumber = phone;
	DarkestSecret = secret;
}
