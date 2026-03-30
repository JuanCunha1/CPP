/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarques <jmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 10:28:23 by jmarques          #+#    #+#             */
/*   Updated: 2026/03/25 10:28:25 by jmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

static void	printWelcome(void) {
	std::cout <<"*-------------------------------------------*\n"
				"|                                           |\n"
				"|                 Jmarques                  |\n"
				"|                  Phone                    |\n"
				"|                   Book                    |\n"
				"|                                           |\n"
				"|          ADD - Add a new contact          |\n"
				"|          SEARCH - Display a contact       |\n"
				"|          EXIT - Exit PhoneBook            |\n"
				"|                                           |\n"
				"*-------------------------------------------*" << std::endl;
}

static bool inline	inputIsValid(std::string input) {
	return (input == "ADD" || input == "SEARCH" || input == "EXIT");
}

static std::string	getInput() {
	std::string	input;

	while (1)
	{
		getline(std::cin, input);
		if (std::cin.eof() == true) {
			std::cin.clear();
			clearerr(stdin);
			std::cout << "\n";
			return ("");
		}
		if (!input.empty() && inputIsValid(input))
			break ;
		std::cin.clear();
		std::cout << "Please insert a valid input" << std::endl;
	}
	return (input);
}

int	main(void) {
	std::string	input;
	PhoneBook	phone;

	printWelcome();
	while(1)
	{
		std::cout << "Option: ";
		input = getInput();
		if (input == "ADD")
			phone.add();
		else if (input == "SEARCH")
			phone.search();
		else
		{
			std::cout << "See ya." << std::endl;
			return (EXIT_SUCCESS);
		}
	}
	return (EXIT_SUCCESS);
}
