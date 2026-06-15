/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 10:47:22 by acohaut           #+#    #+#             */
/*   Updated: 2026/05/27 10:58:41 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

//Constructors
AForm::AForm() 
	: _name( "Default" ), _sign( false ), _sign_grade( 150 ), _exec_grade( 150 )
{}

AForm::AForm( AForm const& copy )
	: _name( copy._name ), _sign( copy._sign ), 
	_sign_grade( copy._sign_grade ), _exec_grade( copy._exec_grade )
{}

AForm::AForm( std::string const& name,
		unsigned short const& sign_grade,
		unsigned short const& exec_grade)
	: _name( name ), _sign( false ), 
	_sign_grade( sign_grade ), _exec_grade( exec_grade )
{
	if (_sign_grade < 1 || _exec_grade < 1)
		throw AForm::GradeTooHighException();
	if (_sign_grade > 150 || _exec_grade > 150)
		throw AForm::GradeTooLowException();
}

//Destructor
AForm::~AForm() {}

//Overload operator=
AForm& AForm::operator=( AForm const& copy )
{
    if (this != &copy)
    {
		this->_sign = copy.getSign();
    }
    return *this;
}

//Overload operator<<
std::ostream&	operator<<( std::ostream & out, AForm const& form )
{
	out << form.getName() << ":" << std::endl
		<< "signed ? (true or false) -> " << form.getSign() << std::endl
		<< "grade needed to sign -> " << form.getSignGrade() << std::endl
		<< "grade needed to execute -> " << form.getExecGrade() << std::endl;
	return ( out );
}

//Getters
const std::string		AForm::getName() const
{
	return ( this->_name );
}

bool					AForm::getSign() const
{
	return ( this->_sign );
}

unsigned short	AForm::getSignGrade() const
{
	return ( this->_sign_grade );
}

unsigned short	AForm::getExecGrade() const
{
	return ( this->_exec_grade );
}

//Methodes
void					AForm::beSigned( Bureaucrat const& a )
{
	if ( a.getGrade() <= this->_sign_grade )
	{
		if (this->_sign == false)
			this->_sign = true;
		else
			throw AForm::AFormAlreadySigned();
	}
	else
		throw AForm::GradeTooLowException();
}

void					AForm::execute( Bureaucrat const& a )
{
	if ( this->_sign == false )
		throw AForm::AFormNotSigned();
	if ( this->_exec_grade < a.getGrade() )
		throw AForm::GradeTooLowException();
	else
		this->executing();
}

//Nested class exception
const char*	AForm::GradeTooLowException::what() const throw()
{
	return ( "grade too low." );
}

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ( "grade too high." );
}

const char*	AForm::AFormAlreadySigned::what() const throw()
{
	return ( "form already signed." );
}

const char*	AForm::AFormNotSigned::what() const throw()
{
	return ( "form is not signed." );
}
