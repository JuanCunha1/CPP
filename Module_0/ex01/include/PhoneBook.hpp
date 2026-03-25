/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarques <jmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 10:28:13 by jmarques          #+#    #+#             */
/*   Updated: 2026/03/25 10:28:14 by jmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <string>
# include <iomanip>
# include <cstdlib>
# include <stdio.h>

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
