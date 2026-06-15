/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 10:48:33 by acohaut           #+#    #+#             */
/*   Updated: 2026/05/27 10:59:28 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//Constructors
RobotomyRequestForm::RobotomyRequestForm() 
	: AForm( "RobotomyRequestForm", 72, 45 ), _target( "empty" ), _robotomized( 0 )
{}

RobotomyRequestForm::RobotomyRequestForm( std::string const& target ) 
	: AForm( "RobotomyRequestForm", 72, 45 ), _target( target ), _robotomized( 0 )
{}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const& copy )
	: AForm( copy ), _target( copy._target )
{}

//Destructor
RobotomyRequestForm::~RobotomyRequestForm() {}

//Overload operator=
RobotomyRequestForm& RobotomyRequestForm::operator=( RobotomyRequestForm const& copy )
{
    if (this != &copy)
    {
		;
    }
    return *this;
}

//Methode
void		RobotomyRequestForm::executing()
{
	if (_robotomized % 2)
		std::cout << "bzzzzbrruuubroom " << this->_target << " robotomised." << std::endl;
	else
		std::cout << "robotomy failed." << std::endl;
	_robotomized++;
}
