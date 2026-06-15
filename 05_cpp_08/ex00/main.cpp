/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/05 12:39:57 by acohaut           #+#    #+#             */
/*   Updated: 2026/06/08 11:09:44 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <iostream>
#include <algorithm>
#include "easyfind.hpp"

int	main( int argc, char **argv )
{
	if ( argc != 2 )
	{
		std::cerr << "Usage: ./containers00 \"int literal\" (between 0 and 200)" << std::endl;
		return ( 1 );
	}
	int	to_find = std::atoi( argv[1] );
	if ( to_find < 0 || to_find > 200 )
	{
		std::cerr << "Error: int literal not valid." << std::endl;
		return ( 1 );
	}
	//Initialize int vector container
	std::vector<int> tab(100, 0);

	//Algorithms
	std::srand(time(0));
	std::generate(tab.begin(), tab.end(), Randomise(200));
	std::for_each(tab.begin(), tab.end(), Display<int>());
	std::cout << std::endl;

	//Initialize int vector iterator
	std::vector<int>::iterator finded;
	
	//easyfind function
	try 
	{
		finded = easyfind( tab, to_find );
		if ( finded == tab.end() )
			std::cout <<  to_find << " not finded in tab.." << std::endl;
		else
			std::cout <<  to_find << " finded in tab !" << std::endl;
	}
	catch ( std::exception & e )
	{
		std::cerr << to_find << e.what();
	}
	return (0);
}
