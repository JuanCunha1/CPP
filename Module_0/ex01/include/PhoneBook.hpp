#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {

private:

	Contact contacts[8];
	int		i;

public:

	PhoneBook(void);

	void	add(void);
	void	search(void);
	void	display(int index);
	void	addTestContact(std::string first, std::string last,
							std::string nick, std::string phone,
							std::string secret);
};
#endif
