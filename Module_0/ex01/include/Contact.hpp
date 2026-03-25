/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarques <jmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 10:28:05 by jmarques          #+#    #+#             */
/*   Updated: 2026/03/25 10:28:08 by jmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <cstdlib>
# include <stdio.h>
# include <limits>

using std::cout;
using std::cin;
using std::endl;

class Contact {

private:

	std::string	Name;
	std::string	LastName;
	std::string	Nickname;
	std::string	PhoneNumber;
	std::string	DarkestSecret;

	std::string format_field(std::string str);

public:

	bool	fillLine(std::string out, std::string *in);
	bool	addContact(void);
	void	showContacts(int index);
	void	displayContact(void);
	void	addTestContact(std::string first, std::string last,
                               std::string nick, std::string phone,
                               std::string secret);

};

#endif
