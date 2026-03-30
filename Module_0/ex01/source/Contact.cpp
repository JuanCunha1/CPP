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

Contact::Contact() {
}

Contact::~Contact() {
}

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

bool isNumber(std::string &pn) {
	size_t	i;

	if (pn.empty())
		return (false);
	for (i = 0; i < pn.length(); i++) {
		if (!std::isdigit(pn[i])) {
			std::cout << "Invalid number\n";
			return (false);
		}
	}
	return (true);
}

int	Contact::isPhoneNumber(std::string &pn) {
	if (pn.empty())
		return (false);
	if (!isNumber(pn))
		return (false);
	if (pn.length() < 3) {
		std::cout << "Too short\n";
		return (false);
	}
	return (true);
}

bool Contact::addContact(void) {
	std::string	name;
	std::string last;
	std::string nick;
	std::string phone;
	std::string secret;

	if (!fillLine("Firstname: ", name))
		return (false);
	if (!fillLine("Lastname: ",last))
		return (false);
	if (!fillLine("Nickname: ", nick))
		return (false);
	if (!fillLine("Number: ", phone))
		return (false);
	while (!isPhoneNumber(phone)) {
		if (!fillLine("Number: ", phone))
			return (false);
	}
	if (!fillLine("Darkest secret: ", secret))
		return (false);
	Name = name;
	LastName = last;
	Nickname = nick;
	PhoneNumber = phone;
	DarkestSecret = secret;
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
