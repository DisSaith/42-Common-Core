/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 14:12:35 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/10 17:03:33 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"

class HumanB
{
	private:
		std::string _name;
		Weapon		*_weapon;
	
	public:
		HumanB(std::string const& name);
		~HumanB(void);
		
		void	setWeapon(Weapon & weapon);
		void	attack(void);
};

#endif
