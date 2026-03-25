/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarques <jmarques@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 15:02:44 by jmarques          #+#    #+#             */
/*   Updated: 2026/03/12 15:02:47 by jmarques         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char** argv) {
	int j;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	j = 1;
	while(j < argc)
	{
		for (int i = 0; argv[j][i] != '\0' ; i++)
		{
			std::cout << (char)std::toupper(argv[j][i]);
		}
		j++;
	}
	std::cout << std::endl;
	return (0);
}
