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

class Contact {

private:

	std::string	Name;
	std::string	LastName;
	std::string	Nickname;
	std::string	PhoneNumber;
	std::string	DarkestSecret;

	std::string format_field(std::string str);

public:
	bool	addContact(void);
	void	showContacts(int index);
	void	displayContact(void) const;
	int		isPhoneNumber(std::string &pn);
};

bool	fillLine(std::string prompt, std::string &input);
#endif
