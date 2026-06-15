/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 09:59:33 by acohaut           #+#    #+#             */
/*   Updated: 2026/05/27 14:39:38 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main( void )
{
	Bureaucrat	manager( "Manager", 1 );
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "TEST 1 : " << std::endl;
	try 
	{
		Intern		stagiaire;
		AForm		*test1;

		test1 = stagiaire.makeForm( "shrubbery creation", "test1" );
		manager.signForm( *test1 );
		manager.executeForm( *test1 );
		delete test1;
	}
	catch( std::exception const& e )
	{
		std::cerr << "ERROR: " << e.what() << std::endl;
	}
	
	std::cout << "-----------------------------------------------" << std::endl;
	std::cout << "TEST 2 : " << std::endl;
	AForm	*form1 = NULL;
	AForm	*form2 = NULL;
	AForm	*form3 = NULL;
	try
	{
		Intern	stagiaire2;
		
		form2 = stagiaire2.makeForm( "robotomy request", "target" );
		form3 = stagiaire2.makeForm( "presidential pardon", "target" );
		form1 = stagiaire2.makeForm( "wrong", "target" );
	}
	catch( std::exception const& e )
	{
		std::cerr << "ERROR: " << e.what() << std::endl;
	}
	if (form1)
		delete form1;
	if (form2)
		delete form2;
	if (form3)
		delete form3;
	return (0);
}
