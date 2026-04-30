/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 10:50:11 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/23 10:50:12 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal() 
{
	this->_type = "Cat";
	std::cout << "\033[31m" << _type << "\033[0m: "
			<< "Cat default constructor." << std::endl;
}

Cat::Cat( std::string type ) : Animal( type ) 
{
	std::cout << "\033[31m" << _type << "\033[0m: "
			<< "Cat constructor." << std::endl;
}

Cat::~Cat() 
{
	std::cout << "\033[31m" << _type << "\033[0m: "
			<< "Cat destructor." << std::endl;
}

Cat::Cat( Cat const& copy ) : Animal( copy )
{
    //*this = copy;
}

Cat& Cat::operator=( Cat const& copy )
{
    if (this != &copy)
    {
		this->_type = copy._type;
    }
    return *this;
}

void	Cat::makeSound() const
{
	std::cout << "\033[34m[makeSound]\033[0m	" 
			<< "\033[31m" << _type << "\033[0m"
			<< " meeeeeoooooooow #miaou." << std::endl;
}
