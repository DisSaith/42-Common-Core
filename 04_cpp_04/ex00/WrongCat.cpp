/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 10:51:05 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/23 10:51:06 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() 
{
	this->_type = "WrongCat";
	std::cout << "\033[31m" << _type << "\033[0m: "
			<< "WrongCat default constructor." << std::endl;
}

WrongCat::WrongCat( std::string type ) : WrongAnimal( type ) 
{
	std::cout << "\033[31m" << _type << "\033[0m: "
			<< "WrongCat constructor." << std::endl;
}

WrongCat::~WrongCat() 
{
	std::cout << "\033[31m" << _type << "\033[0m: "
			<< "WrongCat destructor." << std::endl;
}

WrongCat::WrongCat( WrongCat const& copy ) : WrongAnimal( copy )
{
    //*this = copy;
}

WrongCat& WrongCat::operator=( WrongCat const& copy )
{
    if (this != &copy)
    {
		this->_type = copy._type;
    }
    return *this;
}

void	WrongCat::makeSound() const
{
	std::cout << "\033[34m[makeSound]\033[0m	" 
			<< "\033[31m" << _type << "\033[0m"
			<< " wronnnnnng meeeeeoooooooow #miaou." << std::endl;
}
