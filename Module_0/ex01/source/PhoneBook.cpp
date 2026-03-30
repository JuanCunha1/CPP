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

PhoneBook::PhoneBook(void) {
	i = 0;
}

void	PhoneBook::add() {
    contacts[i % 8].addContact();
    i++;
}

void	PhoneBook::search() {
	int					index = 0;
	std::string 		contactSearch;
	int					max = std::min(i, 8);
	std::stringstream	prompt;

	while(index < max)
	{
		contacts[index].showContacts(index);
		index++;
	}
	prompt << "Enter index (0-" << max - 1 << "): ";
	if (!fillLine(prompt.str(), contactSearch))
		return ;
	index = std::atoi(contactSearch.c_str());
	if (index < 0 || index >= max)
		std::cout << "Contact not available" << std::endl;
	else
		contacts[index].displayContact();
}
