/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 14:31:08 by acohaut           #+#    #+#             */
/*   Updated: 2026/06/12 12:50:44 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main( int ac, char **av )
{
	PmergeMe	program;

	if ( ac < 2 )
	{
		std::cerr << "Usage: ./PmergeMe [range of random numbers].\n"; 
		return ( 1 );
	}
	try
	{
		program.checkArguments( av );
		program.sorting();
	}
	catch( std::exception & e )
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}
	return (0);
}
