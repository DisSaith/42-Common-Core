/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <acohaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 17:01:20 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/24 17:28:26 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name( "Default" )
{
	if (DEBUGGING)
		std::cout << this->_name <<": Character default constructor." << std::endl;
	for (int i = 0 ; i < MAX_INVENTORY ; i++)
		_inventory[i] = NULL;
}

Character::~Character()
{
	if (DEBUGGING)
		std::cout << this->_name <<": Character destructor." << std::endl;
	for (int i = 0 ; i < MAX_INVENTORY ; i++)
	{
		if (this->_inventory[i] != NULL)
		{
			if (DEBUGGING)
				std::cout << this->_name << ": delete " << this->_inventory[i]->getType() << " index " << i << std::endl;
			delete this->_inventory[i];
		}
	}
}

Character::Character( Character const& copy ) : _name( copy.getName() + "_copy")
{	
	if (DEBUGGING)
		std::cout << this->_name <<": Character copy constructor." << std::endl;
	for (int i = 0 ; i < MAX_INVENTORY ; i++)
		this->_inventory[i] = copy.copyInventory( i );
}

Character::Character( std::string const& name ) : _name( name )
{
	if (DEBUGGING)
		std::cout << this->_name <<": Character name constructor." << std::endl;
	for (int i = 0 ; i < MAX_INVENTORY ; i++)
		_inventory[i] = NULL;
}

Character& Character::operator=( Character const& copy )
{
    if (this != &copy)
    {
		if (DEBUGGING)
			std::cout << this->_name <<": Character overload operator=." << std::endl;
		for (int i = 0 ; i < MAX_INVENTORY ; i++)
		{
			if (this->_inventory[i] != NULL)
				delete this->_inventory[i];
			this->_inventory[i] = copy.copyInventory( i );
		}
    }
    return *this;
}

std::string const&	Character::getName() const
{
	return( this->_name );
}

void				Character::equip( AMateria* m )
{
	if (m == NULL)
	{
		std::cout << this->_name << ": [equip] can't equip this." << std::endl; 
		return ;
	}
	for (int i = 0 ; i < MAX_INVENTORY ; i++)
	{
		if (this->_inventory[i] == NULL)
		{
			this->_inventory[i] = m;
			std::cout << this->_name << ": [equip] " << this->_inventory[i]->getType() 
				<< " index " << i << std::endl;
			return ;
		}
	}
	std::cout << this->_name << ": [equip] inventory full" << std::endl;
}

void				Character::unequip( int idx )
{
	if (idx < 0 || idx >= MAX_INVENTORY)
	{
		std::cout << this->_name << ": [unequip] wrond index" << std::endl;
		return ;
	}
	if (this->_inventory[idx] != NULL)
	{
		std::cout << this->_name << ": [unequip] " << this->_inventory[idx]->getType() 
			<< " index "<< idx << std::endl;
		this->_inventory[idx] = NULL;
	}
	else
		std::cout << this->_name << ": [unequip] this slot is empty." << std::endl;

}

void				Character::use( int idx, ICharacter & target )
{
	if (idx < 0 || idx >= MAX_INVENTORY)
	{
		std::cout << this->_name << ": [use] wrond index" << std::endl;
		return ;
	}
	else if (this->_inventory[idx] != NULL)
	{
		std::cout << this->_name << ": [use] " << this->_inventory[idx]->getType() << " ";
		this->_inventory[idx]->use( target );
	}
	else
		std::cout << this->_name << ": [use] can't use this." << std::endl;

}

AMateria*			Character::copyInventory( int const& idx ) const
{
	if (idx < 0 || idx >= MAX_INVENTORY)
	{
		std::cout << this->_name << ": [copyInventory] wrong index" << std::endl;
		return ( NULL );
	}
	if ( this->_inventory[idx] == NULL)
		return ( NULL );
	else
		return ( this->_inventory[idx]->clone() );
}

AMateria*			Character::saveAddress( int const& idx ) const
{
	if (idx < 0 || idx >= MAX_INVENTORY)
	{
		std::cout << this->_name << ": [saveAddress] wrong index" << std::endl;
		return ( NULL );
	}
	if (this->_inventory[idx] != NULL)
	{
		std::cout << this->_name << ": [saveAddress] " << this->_inventory[idx]->getType() 
			<< " index "<< idx << std::endl;
		return ( this->_inventory[idx] );
	}
	else
		std::cout << this->_name << ": [saveAddress] this slot is empty." << std::endl;
	return ( NULL );
}
