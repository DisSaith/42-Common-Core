/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 10:48:16 by acohaut           #+#    #+#             */
/*   Updated: 2026/05/27 10:59:41 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

//Constructors
PresidentialPardonForm::PresidentialPardonForm() 
	: AForm( "PresidentialPardonForm", 25, 5 ), _target( "empty" )
{}

PresidentialPardonForm::PresidentialPardonForm( std::string const& target ) 
	: AForm( "PresidentialPardonForm", 25, 5 ), _target( target )
{}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const& copy )
	: AForm( copy ), _target( copy._target )
{}

//Destructor
PresidentialPardonForm::~PresidentialPardonForm() {}

//Overload operator=
PresidentialPardonForm& PresidentialPardonForm::operator=( PresidentialPardonForm const& copy )
{
    if (this != &copy)
    {
		;
    }
    return *this;
}

//Methode
void		PresidentialPardonForm::executing()
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
