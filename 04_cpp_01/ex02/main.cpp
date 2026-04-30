/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 14:13:44 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/08 14:13:46 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string	stringA = "HI THIS IS BRAIN";
	std::string *stringPTR = &stringA;
	std::string &stringREF = stringA;

	std::cout << "stringA address: " << &stringA << std::endl
			<< "stringPTR memory held address: " << stringPTR << std::endl
			<< "stringREF memory held address: " << &stringREF << std::endl 
			<< std::endl;
	std::cout << "stringA value: " << stringA << std::endl
			<< "stringPTR pointed value: " << *stringPTR << std::endl
			<< "stringREF pointed value: " << stringREF << std::endl;

	return (0);
}
