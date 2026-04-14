/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarques <jmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 10:27:51 by jmarques          #+#    #+#             */
/*   Updated: 2026/03/25 10:27:53 by jmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : i(0) {
}
PhoneBook::~PhoneBook(void) {
	std::cout << "See ya" << std::endl;
}
void	PhoneBook::add() {
    if (!contacts[i % MAX_CONTACTS].addContact())
    	return ;
    i++;
}

void	PhoneBook::search() {
	int					index = 0;
	std::string 		contactSearch;
	int					max = std::min(i, MAX_CONTACTS);
	std::stringstream	prompt;

	if (i == 0) {
		std::cout << "No contact available \n";
		return ;
	}
	while(index < max)
	{
		contacts[index].showContacts(index);
		index++;
	}
	index = 0;
	prompt << "Enter index (0-" << max - 1 << "): ";
	if (!fillLine(prompt.str(), contactSearch))
		return ;
	if (!isNumber(contactSearch))
		return ;
	if (index < 0 || index >= max)
		std::cout << "Contact not available" << std::endl;
	else
		contacts[index].displayContact();
}
