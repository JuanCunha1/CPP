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
				"*-------------------------------------------*" << endl;
}

static bool inline	inputIsValid(std::string input) {
	return (input == "ADD" || input == "SEARCH" || input == "EXIT");
}

static std::string	getInput() {
	std::string	input;

	while (1)
	{
		getline(cin, input);
		if (cin.eof() == true) {
			cin.clear();
			clearerr(stdin);
			exit(0);
		}
		if (!input.empty() && inputIsValid(input))
			break ;
		cin.clear();
		cout << "Please insert a valid input" << endl;
	}
	return (input);
}

int	main(void) {
	std::string	input;
	PhoneBook	phone;

	printWelcome();
	while(1)
	{
		cout << "Option: ";
		input = getInput();
		if (input == "ADD")
			phone.add();
		else if (input == "SEARCH")
			phone.search();
		else
		{
			cout << "See ya." << endl;
			return (EXIT_SUCCESS);
		}
	}
	return (EXIT_SUCCESS);
}
/*
int main(void) {
	PhoneBook	pb;
	std::string	input;

	pb.addTestContact("1", "A", "A", "111", "S1");
	pb.addTestContact("2", "B", "B", "222", "S2");
	pb.addTestContact("3", "C", "C", "333", "S3");
	pb.addTestContact("4", "D", "D", "444", "S4");
	pb.addTestContact("5", "E", "E", "555", "S5");
	pb.addTestContact("6", "F", "F", "666", "S6");
	pb.addTestContact("7", "G", "G", "777", "S7");
	pb.addTestContact("8", "H", "H", "888", "S8");
	pb.addTestContact("9", "I", "I", "999", "S9");

	printWelcome();
	while(1) {
		cout << "Option: ";
		input = getInput();
		if (input == "ADD")
			pb.add();
		else if (input == "SEARCH")
			pb.search();
		else {
			cout << "See ya." << endl;
			return (EXIT_SUCCESS);
		}
	}
	return (EXIT_SUCCESS);
}
*/
