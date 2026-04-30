/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 14:46:39 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/24 16:00:46 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("Default")
{
	if (DEBUGGING)
		std::cout << "AMateria default constructeur." << std::endl;
}

AMateria::~AMateria()
{
	if (DEBUGGING)
		std::cout << "AMateria destructeur." << std::endl; 
}

AMateria::AMateria( AMateria const& copy ) : _type(copy.getType())
{
	if (DEBUGGING)
		std::cout << "AMateria copy constructeur" << std::endl;
}

AMateria::AMateria( std::string const& type ) : _type(type)
{	
	if (DEBUGGING)
		std::cout << "AMateria name constructeur" << std::endl;
}

AMateria& AMateria::operator=( AMateria const& copy )
{
    if (this != &copy)
    {
		if (DEBUGGING)
			std::cout << "AMateria overload operator=" << std::endl;
    }
    return *this;
}

std::string const&  AMateria::getType() const
{
	return (this->_type);
}

void				AMateria::use(ICharacter & target)
{
	(void)target;
}
