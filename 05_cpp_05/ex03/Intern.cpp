/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 09:59:51 by acohaut           #+#    #+#             */
/*   Updated: 2026/05/27 14:40:53 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

//Constructors
Intern::Intern() {}

Intern::Intern( Intern const& copy ) { (void)copy; }

//Destructor
Intern::~Intern() {}

//Opperators overload
Intern& Intern::operator=( Intern const& copy )
{
	(void)copy;
	return *this;
}

//Methodes
AForm*		Intern::makeShrubberyCreation( std::string const& target )
{
	return ( new ShrubberyCreationForm( target ) );
}

AForm*		Intern::makeRobotomyRequest( std::string const& target )
{
	return ( new RobotomyRequestForm( target ) );
}

AForm*		Intern::makePresidentialPardon( std::string const& target )
{
	return ( new PresidentialPardonForm( target ) );
}

AForm*			Intern::makeForm( std::string const& formName, std::string const& target )
{

	AForm*				(*forms[3])( std::string const& target );
	std::string			formNames[3];
	
	forms[0] = Intern::makeShrubberyCreation;
	forms[1] = Intern::makeRobotomyRequest;
	forms[2] = Intern::makePresidentialPardon;
	formNames[0] = "shrubbery creation";
	formNames[1] = "robotomy request";
	formNames[2] = "presidential pardon";

	for ( unsigned short i = 0 ; i < 3 ; i++ )
	{
		if ( formNames[i] == formName )
		{
			std::cout << "Intern creates " << formName << std::endl;
			return ( forms[i]( target ) );
		}
	}
	throw Intern::FormNameNotRecognised( formName );
}

//Nested class exception
Intern::FormNameNotRecognised::FormNameNotRecognised() : exception(), _errorMessage( "form name not recognised" ) {}

Intern::FormNameNotRecognised::FormNameNotRecognised( std::string const& formName )
	: exception(), _errorMessage( "\"" + formName + "\" form name not recognised" ) {}

Intern::FormNameNotRecognised::~FormNameNotRecognised() throw() {}

const char*		Intern::FormNameNotRecognised::what() const throw()
{
	return ( this->_errorMessage.c_str() );
}
