/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/11 10:55:59 by acohaut           #+#    #+#             */
/*   Updated: 2026/06/11 14:10:42 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main( int ac, char **av )
{
	RPN	program;
	
	if ( ac != 2 )
	{
		std::cerr << "Usage: ./RPN \"inverted Polish maths expression\".\n";
		return (1);
	}
	try
	{
		program.checkArgument( av[1] );
		program.doOperations( av[1] );
	}
	catch( std::exception & e )
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (0);
}
