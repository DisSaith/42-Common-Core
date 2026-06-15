/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 09:59:33 by acohaut           #+#    #+#             */
/*   Updated: 2026/05/27 15:00:00 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main( void )
{
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "TEST 1 : " << std::endl;
	try 
	{
		ShrubberyCreationForm try1("path");
		std::cout << try1 << std::endl;
		Bureaucrat antoine1( "Antoine1", 145 );
		Bureaucrat antoine2( "Antoine2", 1 );
		std::cout << std::endl;
		antoine1.executeForm( try1 );
		antoine1.signForm( try1 );
		antoine1.executeForm( try1 );
		antoine2.executeForm( try1 );
	}
	catch( std::exception const& e )
	{
		std::cerr << "ERROR: " << e.what() << std::endl;
	}
	
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "TEST 2 : " << std::endl;
	try
	{
		RobotomyRequestForm	test2( "Jules" );
		std::cout << test2 << std::endl;
		Bureaucrat jules( "Jules", 45 );
		std::cout << std::endl;
		jules.signForm( test2 );
		jules.executeForm( test2 );
		jules.executeForm( test2 );
	}
	catch( std::exception const& e )
	{
		std::cerr << "ERROR: " << e.what() << std::endl;
	}

	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "TEST 3 : " << std::endl;
	try
	{
		PresidentialPardonForm	test3( "plouc2" );
		std::cout << test3 << std::endl;
		Bureaucrat				plouc1( "plouc1", 1 );
		Bureaucrat				plouc2( "plouc2", 50 );
		std::cout << std::endl;
		plouc1.executeForm( test3 );
		plouc2.signForm( test3 );
		plouc1.signForm( test3 );
		plouc2.executeForm( test3 );
		plouc1.executeForm( test3 );
		std::cout << std::endl << test3;
	}
	catch( std::exception const& e )
	{
		std::cerr << "ERROR: " << e.what() << std::endl;
	}
	return (0);
}
