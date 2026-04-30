/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 14:36:59 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/08 17:29:58 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) : _type("")
{
	return;
}

Weapon::Weapon(std::string const& type) : _type(type)
{
	std::cout << "[" << _type << "] weapon created." << std::endl;
	return;
}

std::string&	Weapon::getType(void)
{
	return this->_type;
}

void			Weapon::setType(std::string const& new_type)
{
	std::cout << "oldtype: [" << _type << "] become: [" 
				<< new_type << "]" << std::endl;
	this->_type = new_type;
}

Weapon::~Weapon(void)
{
	std::cout << "[" << _type << "] weapon destroyed." << std::endl;
	return;
}
