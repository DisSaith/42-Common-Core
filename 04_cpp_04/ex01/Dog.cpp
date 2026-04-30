/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 10:50:19 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/24 13:48:51 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal() 
{
	this->_type = "Dog";
	std::cout << "\033[31m" << _type << "\033[0m: ";
	this->_brain = new Brain();
	std::cout << "\033[31m" << _type << "\033[0m: "
			<< "Dog default constructor." << std::endl;
}

Dog::Dog( std::string type ) : Animal( type ) 
{
	std::cout << "\033[31m" << _type << "\033[0m: ";
	this->_brain = new Brain();
	std::cout << "\033[31m" << _type << "\033[0m: "
			<< "Dog name constructor." << std::endl;
}

Dog::~Dog() 
{
	std::cout << "\033[31m" << _type << "\033[0m: ";
	delete _brain;
	std::cout << "\033[31m" << _type << "\033[0m: "
			<< "Dog destructor." << std::endl;
}

Dog::Dog( Dog const& copy ) : Animal( copy )
{
	std::cout << "\033[31m" << this->_type << "\033[0m: "
			<< "Dog copy constructor." << std::endl;
	std::cout << "\033[31m" << this->_type << "\033[0m: ";
	this->_brain = new Brain();
	for (int i = 0 ; i < 100 ; i++)
		this->setIdeaBrain( i, copy.getIdeaBrain( i ) );
}

Dog& Dog::operator=( Dog const& copy )
{
    if (this != &copy)
    {
		this->_type = copy._type + "_copy";
		std::cout << "\033[31m" << this->_type << "\033[0m: "
			<< "Dog overload operator=." << std::endl;
		if (this->_brain != NULL)
		{
			std::cout << "\033[31m" << this->_type << "\033[0m: ";
			delete _brain;
		}
		std::cout << "\033[31m" << this->_type << "\033[0m: ";
		this->_brain = new Brain();
		for (int i = 0 ; i < 100 ; i++)
			this->setIdeaBrain( i, copy.getIdeaBrain( i ) );
    }
    return *this;
}

void		Dog::makeSound() const
{
	std::cout << "\033[34m[makeSound]\033[0m	" 
			<< "\033[31m" << _type << "\033[0m"
			<< " baaaaaaaaaaaark #waouf." << std::endl;
}

void        Dog::initBrain() const
{
	this->_brain->initIdeas();
}

void        Dog::setIdeaBrain( int const& index, std::string const& idea ) const
{
	if (index < 0 || index > this->_brain->getMaxArray() - 1)
	{
		std::cout << "[setIdeaBrain] Wrong index sorry." << std::endl;
		return ;
	}
	this->_brain->setIdea( index, idea );
}

std::string	Dog::getIdeaBrain( int const& index ) const
{
	if (index < 0 || index > this->_brain->getMaxArray() - 1)
	{
		std::cout << "[getIdeaBrain] Wrong index sorry." << std::endl;
		return ( "NULL" );
	}
	return ( this->_brain->getIdea( index ));
}
