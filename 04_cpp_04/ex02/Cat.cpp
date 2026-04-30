/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 10:50:19 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/24 14:25:09 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal() 
{
	this->_type = "Cat";
	std::cout << "\033[31m" << _type << "\033[0m: ";
	this->_brain = new Brain();
	std::cout << "\033[31m" << _type << "\033[0m: "
			<< "Cat default constructor." << std::endl;
}

Cat::Cat( std::string type ) : AAnimal( type ) 
{
	std::cout << "\033[31m" << _type << "\033[0m: ";
	this->_brain = new Brain();
	std::cout << "\033[31m" << _type << "\033[0m: "
			<< "Cat name constructor." << std::endl;
}

Cat::~Cat() 
{
	std::cout << "\033[31m" << _type << "\033[0m: ";
	delete _brain;
	std::cout << "\033[31m" << _type << "\033[0m: "
			<< "Cat destructor." << std::endl;
}

Cat::Cat( Cat const& copy ) : AAnimal( copy )
{
	std::cout << "\033[31m" << this->_type << "\033[0m: "
			<< "Cat copy constructor." << std::endl;
	std::cout << "\033[31m" << this->_type << "\033[0m: ";
	this->_brain = new Brain();
	for (int i = 0 ; i < 100 ; i++)
		this->setIdeaBrain( i, copy.getIdeaBrain( i ) );
}

Cat& Cat::operator=( Cat const& copy )
{
    if (this != &copy)
    {
		this->_type = copy._type + "_copy";
		std::cout << "\033[31m" << this->_type << "\033[0m: "
			<< "Cat overload operator=." << std::endl;
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

void		Cat::makeSound() const
{
	std::cout << "\033[34m[makeSound]\033[0m	" 
			<< "\033[31m" << _type << "\033[0m"
			<< " baaaaaaaaaaaark #waouf." << std::endl;
}

void        Cat::initBrain() const
{
	this->_brain->initIdeas();
}

void        Cat::setIdeaBrain( int const& index, std::string const& idea ) const
{
	if (index < 0 || index > this->_brain->getMaxArray() - 1)
	{
		std::cout << "[setIdeaBrain] Wrong index sorry." << std::endl;
		return ;
	}
	this->_brain->setIdea( index, idea );
}

std::string	Cat::getIdeaBrain( int const& index ) const
{
	if (index < 0 || index > this->_brain->getMaxArray() - 1)
	{
		std::cout << "[getIdeaBrain] Wrong index sorry." << std::endl;
		return ( "NULL" );
	}
	return ( this->_brain->getIdea( index ));
}
