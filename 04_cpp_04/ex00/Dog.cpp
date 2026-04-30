/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 10:50:19 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/23 10:50:22 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() 
{
	this->_type = "Dog";
	std::cout << "\033[31m" << _type << "\033[0m: "
			<< "Dog default constructor." << std::endl;
}

Dog::Dog( std::string type ) : Animal( type ) 
{
	std::cout << "\033[31m" << _type << "\033[0m: "
			<< "Dog constructor." << std::endl;
}

Dog::~Dog() 
{
	std::cout << "\033[31m" << _type << "\033[0m: "
			<< "Dog destructor." << std::endl;
}

Dog::Dog( Dog const& copy ) : Animal( copy )
{
    //*this = copy;
}

Dog& Dog::operator=( Dog const& copy )
{
    if (this != &copy)
    {
		this->_type = copy._type;
    }
    return *this;
}

void	Dog::makeSound() const
{
	std::cout << "\033[34m[makeSound]\033[0m	" 
			<< "\033[31m" << _type << "\033[0m"
			<< " baaaaaaaaaaaark #waouf." << std::endl;
}
