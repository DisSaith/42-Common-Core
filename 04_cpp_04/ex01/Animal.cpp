/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 10:49:57 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/24 11:45:13 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : _type( "Animal" )
{
	std::cout << "\033[31m" << _type << "\033[0m: "
			<< "Animal default constructor." << std::endl;
}

Animal::Animal( std::string type ) : _type( type ) 
{
	std::cout << "\033[31m" << _type << "\033[0m: "
			<< "Animal constructor." << std::endl;
}

Animal::~Animal() 
{
	std::cout << "\033[31m" << _type << "\033[0m: "
			<< "Animal destructor." << std::endl;
}

Animal::Animal( Animal const& copy )
{
	this->_type = copy._type + "_copy";
    std::cout << "\033[31m" << _type << "\033[0m: "
			<< "Animal copy constructor." << std::endl;
}

Animal& Animal::operator=( Animal const& copy )
{
    if (this != &copy)
    {
	   this->_type = copy._type + "_copy";
	   std::cout << "\033[31m" << _type << "\033[0m: "
			<< "Animal overload operator=." << std::endl;
    }
    return *this;
}

std::string	Animal::getType() const
{
	return (this->_type);
}

void		Animal::makeSound() const
{
	std::cout << "\033[34m[makeSound]\033[0m	" 
			<< "\033[31m" << _type << "\033[0m"
			<< " make a sound." << std::endl;
}
