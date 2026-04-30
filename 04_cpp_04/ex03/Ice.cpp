/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 14:46:39 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/24 16:06:16 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria( "ice" )
{
	if (DEBUGGING)
			std::cout << "Ice default constructor." << std::endl;
}

Ice::~Ice()
{
	if (DEBUGGING)
			std::cout << "Ice destructor." << std::endl;
}

Ice::Ice( Ice const& copy ) : AMateria( copy )
{
	if (DEBUGGING)
			std::cout << "Ice copy constructor." << std::endl;
}

Ice::Ice( std::string const& type ) : AMateria( type )
{
	if (DEBUGGING)
			std::cout << "Ice copy constructor." << std::endl;
}

Ice& Ice::operator=( Ice const& copy )
{
    if (this != &copy)
    {
		if (DEBUGGING)
			std::cout << "Ice overload operator=" << std::endl;
    }
    return *this;
}

AMateria*	Ice::clone() const
{
	return ( new Ice( "ice" ) );
}

void        Ice::use(ICharacter & target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" <<std::endl;
}
