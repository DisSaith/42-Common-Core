/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 10:46:46 by acohaut           #+#    #+#             */
/*   Updated: 2026/05/27 10:46:48 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//Constructors
Form::Form() 
	: _name( "Default" ), _sign( false ), _sign_grade( 150 ), _exec_grade( 150 )
{}

Form::Form( Form const& copy )
	: _name( copy._name ), _sign( copy._sign ), 
	_sign_grade( copy._sign_grade ), _exec_grade( copy._exec_grade )
{}

Form::Form( std::string const& name,
		unsigned short const& sign_grade,
		unsigned short const& exec_grade)
	: _name( name ), _sign( false ), 
	_sign_grade( sign_grade ), _exec_grade( exec_grade )
{
	if (_sign_grade < 1 || _exec_grade < 1)
		throw Form::GradeTooHighException();
	if (_sign_grade > 150 || _exec_grade > 150)
		throw Form::GradeTooLowException();
}

//Destructor
Form::~Form() {}

//Overload operator=
Form& Form::operator=( Form const& copy )
{
    if (this != &copy)
    {
		this->_sign = copy._sign;
    }
    return *this;
}

//Overload operator<<
std::ostream&	operator<<( std::ostream & out, Form const& form )
{
	out << form.getName() << ":" << std::endl
		<< "signed ? (true or false) -> " << form.getSign() << std::endl
		<< "grade needed to sign -> " << form.getSignGrade() << std::endl
		<< "grade needed to execute -> " << form.getExecGrade() << std::endl;
	return ( out );
}

//Getters
const std::string		Form::getName() const
{
	return ( this->_name );
}

bool					Form::getSign() const
{
	return ( this->_sign );
}

unsigned short	Form::getSignGrade() const
{
	return ( this->_sign_grade );
}

unsigned short	Form::getExecGrade() const
{
	return ( this->_exec_grade );
}

//Methodes
void					Form::beSigned( Bureaucrat const& a )
{
	if ( a.getGrade() == this->_sign_grade
		|| a.getGrade() < this->_sign_grade )
	{
		if (this->_sign == false)
			this->_sign = true;
		else
			throw Form::FormAlreadySigned();
	}
	else
		throw Form::GradeTooLowException();
}

//Nested class exception
const char*	Form::GradeTooLowException::what() const throw()
{
	return ( "grade too low." );
}

const char*	Form::GradeTooHighException::what() const throw()
{
	return ( "grade too high." );
}

const char*	Form::FormAlreadySigned::what() const throw()
{
	return ( "form already signed." );
}
