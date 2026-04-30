/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:41:09 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/21 20:04:52 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->_healthPts = 100;
	this->_energyPts = 100;
	this->_attackDmg = 30;
	std::cout << "Default FragTrap created." << std::endl;
	return ;
}

FragTrap::FragTrap( std::string name ) : ClapTrap( name )
{
	this->_healthPts = 100;
	this->_energyPts = 100;
	this->_attackDmg = 30;
	std::cout << "FragTrap " << this->_name << " created." << std::endl
			<< "	He has " << this->_healthPts << " health, "
			<< this->_energyPts << " energy point(s) and "
			<< this->_attackDmg << " attack damage." << std::endl;
	return ;
}

FragTrap::FragTrap( std::string name, unsigned int health,
					unsigned int energy, unsigned int attack )
	: ClapTrap(name, health, energy, attack)
{
	std::cout << "FragTrap " << this->_name << " created." << std::endl
			<< "	He has " << this->_healthPts << " health, "
			<< this->_energyPts << " energy point(s) and "
			<< this->_attackDmg << " attack damage." << std::endl;
	return ;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " destroyed." << std::endl;
	return ;
}

FragTrap::FragTrap( FragTrap const& copy )
{
    *this = copy;
}

FragTrap& FragTrap::operator=( FragTrap const& copy )
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

void	FragTrap::highFivesGuys( void ) const
{
	std::cout << "[FragTrap highFivesGuys]" << std::endl
			<< "	" << this->_name << " wants a High five!" << std::endl;
}