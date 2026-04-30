/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 10:49:57 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/24 14:34:09 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : _type( "AAnimal" )
{
	std::cout << "\033[31m" << _type << "\033[0m: "
			<< "AAnimal default constructor." << std::endl;
}

AAnimal::AAnimal( std::string type ) : _type( type ) 
{
	std::cout << "\033[31m" << _type << "\033[0m: "
			<< "AAnimal constructor." << std::endl;
}

AAnimal::~AAnimal() 
{
	std::cout << "\033[31m" << _type << "\033[0m: "
			<< "AAnimal destructor." << std::endl;
}

AAnimal::AAnimal( AAnimal const& copy )
{
	this->_type = copy._type + "_copy";
    std::cout << "\033[31m" << _type << "\033[0m: "
			<< "AAnimal copy constructor." << std::endl;
}

AAnimal& AAnimal::operator=( AAnimal const& copy )
{
    if (this != &copy)
    {
	   this->_type = copy._type + "_copy";
	   std::cout << "\033[31m" << _type << "\033[0m: "
			<< "AAnimal overload operator=." << std::endl;
    }
    return *this;
}

std::string	AAnimal::getType() const
{
	return (this->_type);
}
