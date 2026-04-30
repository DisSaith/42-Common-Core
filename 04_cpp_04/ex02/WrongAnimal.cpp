/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 10:51:10 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/23 10:51:11 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type( "WrongAnimal" )
{
	std::cout << "\033[31m" << _type << "\033[0m: "
			<< "WrongAnimal default constructor." << std::endl;
}

WrongAnimal::WrongAnimal( std::string type ) : _type( type ) 
{
	std::cout << "\033[31m" << _type << "\033[0m: "
			<< "WrongAnimal constructor." << std::endl;
}

WrongAnimal::~WrongAnimal() 
{
	std::cout << "\033[31m" << _type << "\033[0m: "
			<< "WrongAnimal destructor." << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const& copy )
{
    *this = copy;
}

WrongAnimal& WrongAnimal::operator=( WrongAnimal const& copy )
{
    if (this != &copy)
    {
		this->_type = copy._type;
    }
    return *this;
}

std::string	WrongAnimal::getType() const
{
	return (this->_type);
}

void		WrongAnimal::makeSound() const
{
	std::cout << "\033[34m[makeSound]\033[0m	" 
			<< "\033[31m" << _type << "\033[0m"
			<< " make a wrong sound." << std::endl;
}
