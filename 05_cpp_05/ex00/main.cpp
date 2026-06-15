/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 09:59:33 by acohaut           #+#    #+#             */
/*   Updated: 2026/05/22 13:31:46 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main( void )
{
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "TEST 1 : " << std::endl;
	try 
	{
		Bureaucrat antoine( "Antoine", 1 );
		Bureaucrat test1;
		antoine.increment();
		test1.decrement();
	}
	catch( std::exception const& e )
	{
		std::cerr << "ERROR: " << e.what() << std::endl;
	}
	
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "TEST 2 : " << std::endl;
	try
	{
		Bureaucrat test2( "Brutus", 170 );
	}
	catch( std::exception const& e )
	{
		std::cerr << "ERROR: " << e.what() << std::endl;
	}

	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "TEST 3 : " << std::endl;
	try
	{
		Bureaucrat test3( "Jules", 150 );
		test3.decrement();
	}
	catch( std::exception const& e )
	{
		std::cerr << "ERROR: " << e.what() << std::endl;
	}

	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "TEST 4 : " << std::endl;
	try
	{
		Bureaucrat test4( "Boris", 10 );
		test4.increment();
		test4.increment();
		test4.increment();
		test4.increment();
		test4.decrement();
		std::cout << test4;
	}
	catch( std::exception const& e )
	{
		std::cerr << "ERROR: " << e.what() << std::endl;
	}
	return (0);
}
