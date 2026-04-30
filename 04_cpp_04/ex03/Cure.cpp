/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 14:46:39 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/24 16:02:26 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria( "cure" )
{
	if (DEBUGGING)
		std::cout << "Cure default constructeur." << std::endl;
}

Cure::~Cure()
{	
	if (DEBUGGING)
		std::cout << "Cure destructor." << std::endl;
}

Cure::Cure( Cure const& copy ) : AMateria( copy )
{	
	if (DEBUGGING)
		std::cout << "Cure copy constructeur." << std::endl;
}

Cure::Cure( std::string const& type ) : AMateria( type )
{	
	if (DEBUGGING)
		std::cout << "Cure name constructeur." << std::endl;
}

Cure& Cure::operator=( Cure const& copy )
{
    if (this != &copy)
    {
		if (DEBUGGING)
			std::cout << "Cure overload operator=" << std::endl;
    }
    return *this;
}

AMateria*	Cure::clone() const
{
	return ( new Cure( "cure" ) );
}

void        Cure::use(ICharacter & target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" <<std::endl;
}
