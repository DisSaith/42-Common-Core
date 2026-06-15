/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 09:59:51 by acohaut           #+#    #+#             */
/*   Updated: 2026/05/22 09:59:53 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

//Constructors
Bureaucrat::Bureaucrat() : _name( "Default" ), _grade( 150 ) 
{
	std::cout << "[DEFAULT CONSTRUCTOR] "<< *this;
}

Bureaucrat::Bureaucrat( Bureaucrat const& copy )
	: _name( copy._name ), _grade( copy._grade ) {}

Bureaucrat::Bureaucrat( std::string const& name, unsigned short const& grade )
	: _name( name ), _grade ( grade )
{
	std::cout << "[CONSTRUCTOR] "<< *this;
	if ( this->_grade < 1 )
		throw Bureaucrat::GradeTooHighException();
	else if ( this->_grade > 150 )
		throw Bureaucrat::GradeTooLowException();
}

//Destructor
Bureaucrat::~Bureaucrat() {}

//Opperators overload
Bureaucrat& Bureaucrat::operator=( Bureaucrat const& copy )
{
	if (this != &copy)
	{
		this->_grade = copy._grade;
	}
	return *this;
}

std::ostream&	operator<<( std::ostream & out, Bureaucrat const& crat )
{
	out << crat.getName() << ", bureaucrat grade "
		<< crat.getGrade() << "." << std::endl;
	return ( out );
}

//Getters
const std::string	Bureaucrat::getName() const
{
	return ( this->_name );
}

unsigned short		Bureaucrat::getGrade() const
{
	return ( this->_grade );
}

//Methodes
void				Bureaucrat::increment()
{
	std::cout << "[INCREMENT] " << *this;
	unsigned short	new_grade;

	new_grade = this->getGrade() - 1;
	if ( new_grade < 1 )
		throw Bureaucrat::GradeTooHighException();
	else
		_grade--;
}

void				Bureaucrat::decrement()
{
	std::cout << "[DECREMENT] " << *this;
	unsigned short	new_grade;

	new_grade = this->getGrade() + 1;
	if ( new_grade > 150 )
		throw Bureaucrat::GradeTooLowException();
	else
		_grade++;
}

void				Bureaucrat::signForm( AForm & form )
{
	try
	{
		std::cout << "[signForm] ";
		form.beSigned( *this );
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch( std::exception const& e )
	{
		std::cerr << this->_name << " couldn't sign " << form.getName() 
				<< " because " << e.what() << std::endl;
	}
}

void				Bureaucrat::executeForm( AForm & form )
{
	try
	{
		std::cout << "[executeForm] ";
		form.execute( *this );
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch( std::exception const& e )
	{
		std::cerr << this->_name << " couldn't execute " << form.getName() 
				<< " because " << e.what() << std::endl;
	}

}

//Nested class exception
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	const char* error = "grade too low";
	return ( error );
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	const char*	error = "grade too high";
	return ( error );
}
