#include "Contact.hpp"
#include <limits>

bool	Contact::fillLine(std::string out, std::string *in)
{
	std::string tmp;

	cout << out;
	while (1)
	{
		getline(cin, tmp);
		if (cin.eof() == true)
		{
			cin.clear();
			clearerr(stdin);
			cout << endl;
			return (false);
		}
	    if (!tmp.empty())
	    {
	        *in = tmp;
	        return (true);
	    }
		cout << "No empty fields!" << endl << out;
	}
}

static int         isPhoneNumber(std::string pn)
{
    int	i;

    if ((!std::isdigit(pn[0]) && pn[0] != '+') || (pn[0] == '+' && !std::isdigit(pn[1])))
    {
        cout << "Please enter a valid number (no brackets, only '+' and digits allowed 1 1)" << endl;
        return (false);
    }
    for (i = 1; pn[i]; i++)
    {
        if (!std::isdigit(pn[i]))
        {
            cout << "Please enter a valid number (no brackets, only '+' and digits allowed2 2 )" << endl;
            return (false);
        }
    }
    if ((pn[0] == '+' && i < 4) || i < 3)
    {
        cout << "Please enter a valid number (min 3 digits)" << endl;
        return (false);
    }
    return (true);
}

bool Contact::addContact(void)
{
	Contact		contact;
	std::string tmp_num;

	if (!fillLine("Firstname: ", &contact.Name))
		return (false);
    if (!fillLine("Lastname: ", &contact.LastName))
    	return (false);
    if (!fillLine("Nickname: ", &contact.Nickname))
    	return (false);
    if (!fillLine("Number: ", &tmp_num))
    	return (false);
    while (!isPhoneNumber(tmp_num))
    {
        if (!fillLine("Number: ", &tmp_num))
        	return (false);
    }
    contact.PhoneNumber = tmp_num;
    if (!fillLine("Darkest secret: ", &contact.DarkestSecret))
    	return (false);
    *this = contact;
    return (true);
}

std::string Contact::format_field(std::string str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void	Contact::showContacts(int index)
{
	cout << std::setw(10) << index << "|"
				<< std::setw(10) << format_field(Name) << "|"
				<< std::setw(10) << format_field(LastName) << "|"
				<< std::setw(10) << format_field(Nickname)
				<< endl;
}

void	Contact::displayContact(void)
{
	cout << "Name: " << Name << endl;
	cout << "Last name: " << LastName << endl;
	cout << "Nickname: " << Nickname << endl;
	cout << "Phone number: " << PhoneNumber << endl;
	cout << "Darkest secret: " <<DarkestSecret << endl;
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
