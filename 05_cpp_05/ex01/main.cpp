/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 09:59:33 by acohaut           #+#    #+#             */
/*   Updated: 2026/05/27 10:45:59 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main( void )
{
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "TEST 1 : " << std::endl;
	try 
	{
		Form	try1( "form1", 1, 150 );
		std::cout << try1;
		Bureaucrat antoine1( "Antoine1", 1 );
		Bureaucrat antoine2( "Antoine2", 1 );
		antoine1.signForm( try1 );
		antoine2.signForm( try1 );
		std::cout << try1;
	}
	catch( std::exception const& e )
	{
		std::cerr << "ERROR: " << e.what() << std::endl;
	}
	
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "TEST 2 : " << std::endl;
	try
	{
		Bureaucrat test2( "Brutus", 150 );
		Form		form2( "form2", 50, 50 );
		test2.signForm( form2 );
		std::cout << form2;
	}
	catch( std::exception const& e )
	{
		std::cerr << "ERROR: " << e.what() << std::endl;
	}

	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "TEST 3 : " << std::endl;
	try
	{
		Bureaucrat	test3( "Jules", 75 );
		Form		form3( "form3", 75, 75 );
		test3.signForm( form3 );
		std::cout << form3;
	}
	catch( std::exception const& e )
	{
		std::cerr << "ERROR: " << e.what() << std::endl;
	}
	return (0);
}
