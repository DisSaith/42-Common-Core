/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:41:09 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/21 19:55:45 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "Default ScavTrap created." << std::endl;
	return ;
}

//ScavTrap::ScavTrap( std::string name ) -> call default mother constructor
ScavTrap::ScavTrap( std::string name ) : ClapTrap( name )
{
	//this->_name = name;
	this->_healthPts = 100;
	this->_energyPts = 50;
	this->_attackDmg = 20;
	this->_gateKeeping = false;
	std::cout << "ScavTrap " << this->_name << " created." << std::endl;
	return ;
}

ScavTrap::ScavTrap( std::string name, unsigned int health,
					unsigned int energy, unsigned int attack )
	: ClapTrap(name, health, energy, attack)
{
	std::cout << "ScavTrap " << this->_name << " created." << std::endl;
	return ;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " destroyed." << std::endl;
	return ;
}

ScavTrap::ScavTrap( ScavTrap const& copy )
{
    *this = copy;
}

ScavTrap& ScavTrap::operator=( ScavTrap const& copy )
{
    if (this != &copy)
    {
		this->_name = copy._name;
		this->_healthPts = copy._healthPts;
		this->_energyPts = copy._energyPts;
		this->_attackDmg = copy._attackDmg;
		this->_gateKeeping = copy._gateKeeping;
    }
    return *this;
}

void	ScavTrap::attack( std::string const& target )
{
	if (this->_energyPts == 0 || this->_healthPts == 0)
	{
		std::cout << "ScavTrap " << this->_name << " can't attack." << std::endl;
		if (this->_healthPts == 0)
			std::cout << "	He's dead." << std::endl;
		else
			std::cout << "	He has no more energy points." << std::endl;
		return ;
	}

	std::cout << "ScavTrap " << this->_name << " attacks " << target
				<< ", causing " << this->_attackDmg << " point(s) of damage!"
				<< std::endl;
	this->_energyPts--;
	std::cout << "	He has now " << this->_energyPts << " energy point(s)."
				<< std::endl;
}

void	ScavTrap::guardGate() 
{
	if (this->_gateKeeping == true)
	{
		std::cout << "ScavTrap " << this->_name << " stops holding the gate."
					<< std::endl;
		this->_gateKeeping = false;
	}
	else
	{
		std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." 
				<< std::endl;
		this->_gateKeeping = true;
	}
}
