#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <string>
# include <iomanip>
# include <cstdlib>

class Contact {
	private:
		std::string	Name;
		std::string	LastName;
		std::string	Nickname;
		std::string	PhoneNumber;
		std::string	DarkestSecret;

		std::string format_field(std::string str);
	public:
		Contact addContact(void);
		void	showContacts(int index);
		void	displayContact(void);
		void	addTestContact(std::string first, std::string last,
                               std::string nick, std::string phone,
                               std::string secret);
};
#endif
