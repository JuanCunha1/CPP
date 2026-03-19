#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <iostream>
# include <string>
# include <iomanip>

class Contact {
	private:
		std::string	Name;
		std::string	LastName;
		std::string	Nickname;
		int			PhoneNumber;
		std::string	DarkestSecret;

		std::string format_field(std::string str);
	public:
		Contact add_contact(void);
		void	show_contacts(int index);
		void	display_contact(void);
};
#endif
