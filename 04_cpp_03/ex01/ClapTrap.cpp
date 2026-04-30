/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:41:09 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/21 20:29:42 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() 
	: _name( "" ), _healthPts( 0 ), _energyPts( 0 ), _attackDmg( 0 )
{
	std::cout << "Default ClapTrap created." << std::endl;
	return ;
}

ClapTrap::ClapTrap( std::string name ) 
	: _name( name ), _healthPts( 10 ), _energyPts( 10 ), _attackDmg( 0 )
{
	std::cout << "ClapTrap " << this->_name << " created." << std::endl;
	return ;
}

ClapTrap::ClapTrap( std::string name, unsigned int health,
					unsigned int energy, unsigned int attack )
	: _name( name ), _healthPts( health ), 
		_energyPts( energy ), _attackDmg( attack )
{
	std::cout << "ClapTrap " << this->_name << " created." << std::endl;
	return ;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " destroyed." << std::endl;
	return ;
}

ClapTrap::ClapTrap( ClapTrap const& copy )
{
    *this = copy;
}

ClapTrap& ClapTrap::operator=( ClapTrap const& copy )
{
    if (this != &copy)
    {
		this->_name = copy._name;
		this->_healthPts = copy._healthPts;
		this->_energyPts = copy._energyPts;
		this->_attackDmg = copy._attackDmg;
    }
    return *this;
}

void	ClapTrap::attack( std::string const& target )
{
	if (this->_energyPts == 0 || this->_healthPts == 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't attack." << std::endl;
		if (this->_healthPts == 0)
			std::cout << "	He's dead." << std::endl;
		else
			std::cout << "	He has no more energy points." << std::endl;
		return ;
	}

	std::cout << "ClapTrap " << this->_name << " attacks " << target
				<< ", causing " << this->_attackDmg << " point(s) of damage!"
				<< std::endl;
	this->_energyPts--;
	std::cout << "	He has now " << this->_energyPts << " energy point(s)."
				<< std::endl;
}

void	ClapTrap::takeDamage( unsigned int amount )
{
	if (this->_healthPts == 0)
		return ;
	std::cout << "ClapTrap " << this->_name << " takes " << amount
				<< " damage(s)." << std::endl;
	if ( amount > this->_healthPts )
		this->_healthPts = 0;
	else
		this->_healthPts -= amount;
	std::cout << "	He has now " << this->_healthPts << " health point(s)."
				<< std::endl;
}

void	ClapTrap::beRepaired( unsigned int amount )
{
	if (this->_energyPts == 0 || this->_healthPts == 0)
		return ;
	if (this->_healthPts == 100)
	{
		std::cout << this->_name << " has already his maximum health !"
					<< std::endl;
		return ;
	}
	else if (this->_healthPts + amount > 100)
		this->_healthPts = 100;
	else
		this->_healthPts += amount;
	this->_energyPts--;
	std::cout << "ClapTrap " << this->_name << " repaired " << amount
				<< " health point(s)." << std::endl
				<< "	He has now " << this->_healthPts << " health point(s)"
				<< " and " << this->_energyPts << " energy point(s)."
				<< std::endl;
}
