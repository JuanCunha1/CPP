/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarques <jmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 10:27:40 by jmarques          #+#    #+#             */
/*   Updated: 2026/03/25 10:27:45 by jmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

bool fillLine(const std::string prompt, std::string& input) {
	std::string	tmp;

	std::cout << prompt;
	while (1) {
		getline(std::cin, tmp);
		if (std::cin.eof() == true) {
			std::cin.clear();
			clearerr(stdin);
			std::cout << std::endl;
			return (false);
		}
		if (!tmp.empty()) {
			input = tmp;
			return (true);
		}
		std::cout << "No empty fields!" << std::endl << prompt;
	}
}

bool isNUmber(std::string &pn) {
	size_t	i;
	if (pn.empty())
		return (false);
	for (i = 1; i < pn.length(); i++) {
		if (!std::isdigit(pn[i])) {
			std::cout << "Invalid number\n";
			return (false);
		}
	}
	return (true);
}

int	Contact::isPhoneNumber(std::string &pn) {
	size_t i;

	if (pn.empty())
		return (false);
	if ((!std::isdigit(pn[0]) && pn[0] != '+') ||
        (pn[0] == '+' && (pn.length() < 2 || !std::isdigit(pn[1])))) {
        std::cout << "Invalid number\n";
		return (false);
	}
	if (!isNUmber(pn)
		return (false);
	if ((pn[0] == '+' && i < 4) || i < 3) {
		std::cout << "Too short\n";
		return (false);
	}
	return (true);
}

bool Contact::addContact(void) {
	Contact		contact;
	std::string tmp_num;

	if (!fillLine("Firstname: ", Name))
		return (false);
	if (!fillLine("Lastname: ",LastName))
		return (false);
	if (!fillLine("Nickname: ", Nickname))
		return (false);
	if (!fillLine("Number: ", tmp_num))
		return (false);
	while (!isPhoneNumber(tmp_num)) {
		if (!fillLine("Number: ", tmp_num))
			return (false);
	}
	PhoneNumber = tmp_num;
	if (!fillLine("Darkest secret: ", DarkestSecret))
		return (false);
	return (true);
}

std::string Contact::format_field(std::string str) {
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void	Contact::showContacts(int index) {
	std::cout << std::setw(10) << index << "|"
				<< std::setw(10) << format_field(Name) << "|"
				<< std::setw(10) << format_field(LastName) << "|"
				<< std::setw(10) << format_field(Nickname)
				<< std::endl;
}

void	Contact::displayContact(void) const {
	std::cout << "Name: " << Name << std::endl;
	std::cout << "Last name: " << LastName << std::endl;
	std::cout << "Nickname: " << Nickname << std::endl;
	std::cout << "Phone number: " << PhoneNumber << std::endl;
	std::cout << "Darkest secret: " << DarkestSecret << std::endl;
}
