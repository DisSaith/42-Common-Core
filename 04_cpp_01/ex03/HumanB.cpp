/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 15:35:57 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/08 17:45:03 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB (std::string const& name) : _name(name), _weapon(NULL)
{
	return ;
}

void	HumanB::setWeapon(Weapon & weapon)
{
	std::cout << _name << " gets weapon " << weapon.getType() << std::endl;
	_weapon = &weapon;
}

void	HumanB::attack(void)
{
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
	else
		std::cout << _name << " can't attack, he has no weapon yet" << std::endl;
}

HumanB::~HumanB (void)
{
	return ;
}
