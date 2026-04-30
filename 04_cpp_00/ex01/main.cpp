/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 17:33:57 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/03 17:33:59 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main (void)
{
	PhoneBook	phonebook;
	std::string	input;
	
	while (true)
	{
		phonebook.display_menu();
		std::getline(std::cin, input);
		if (input == "EXIT")
			break ;
		else if (input == "ADD")
			phonebook.add_a_contact(phonebook);
		else if (input == "SEARCH")
			phonebook.search_a_contact(phonebook);
		else
			std::cout << "You have to choose between \"ADD\", \"SEARCH\" and \"EXIT\". Try again :" << std::endl;
	}
	return (0);
}
