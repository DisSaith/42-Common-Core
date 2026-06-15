/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/03 12:50:59 by acohaut           #+#    #+#             */
/*   Updated: 2026/06/03 14:26:45 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"


int	main( void )
{
	std::cout << "---------- TEST 1 ----------\n\n";
	int	tab[10] = {0, -32, 42, 56, 17, -1, 7, -42, -2030404, 2030303};
	
	std::cout << "[BEFORE INCREMENTATION]\n";
	iter<int>( tab, 10, display<int> );
	
	std::cout << "\n[AFTER INCREMENTATION]\n";
	iter( tab, 10, incrementation<int> );
	iter( tab, 10, display<int> );
	
	std::cout << "---------- TEST 2 ----------\n\n";
	char tab2[5] = {'a', 'z', 'Y', 'B', '4'};

	std::cout << "[BEFORE INCREMENTATION]\n";
	iter( tab2, 5, display<char> );
	
	std::cout << "\n[AFTER INCREMENTATION]\n";
	iter( tab2, 5, incrementation<char> );
	iter( tab2, 5, display<char> );
	return (0);
}
