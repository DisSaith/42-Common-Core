/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 14:12:35 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/08 15:30:33 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"

class HumanA
{
	private:

		std::string _name;
		Weapon		&_weapon;
	
	public:
		HumanA(std::string const& name, Weapon & weapon);
		~HumanA(void);
		void attack(void);
};

#endif
