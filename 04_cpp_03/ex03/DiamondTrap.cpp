/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:41:09 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/21 19:55:33 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap()
{
	this->_name = "Default";
	this->ClapTrap::_name = "Default_clap_name";
	this->_healthPts = FragTrap::_healthPts;
	this->_energyPts = 50;
	this->_attackDmg = FragTrap::_attackDmg;
	this->_gateKeeping = false;
	std::cout << "Default DiamondTrap created." << std::endl;
	return ;
}

DiamondTrap::DiamondTrap( std::string name ) 
{
	this->_name = name;
	this->ClapTrap::_name = name + "_clap_name";
	this->_healthPts = FragTrap::_healthPts;
	this->_energyPts = 50;
	this->_attackDmg = FragTrap::_attackDmg;
	this->_gateKeeping = false;
	std::cout << "DiamondTrap " << this->_name << " created." << std::endl
			<< "	He has " << this->_healthPts << " health, "
			<< this->_energyPts << " energy point(s) and "
			<< this->_attackDmg << " attack damage." << std::endl;
	return ;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_name << " destroyed." << std::endl;
	return ;
}

DiamondTrap::DiamondTrap( DiamondTrap const& copy )
{
    *this = copy;
}

DiamondTrap& DiamondTrap::operator=( DiamondTrap const& copy )
{
    if (this != &copy)
    {
		this->_name = copy._name;
		ClapTrap::_name = copy._name + "_clap_name";
		this->_healthPts = copy._healthPts;
		this->_energyPts = copy._energyPts;
		this->_attackDmg = copy._attackDmg;
		this->_gateKeeping = copy._gateKeeping;
    }
    return *this;
}

void	DiamondTrap::whoAmI() const
{
	std::cout << "[DiamondTrap whoAmI]" << std::endl
			<< "	Hello! I'am " << this->_name << " an instance of ClapTrap named " 
			<< this->ClapTrap::_name << std::endl;
}