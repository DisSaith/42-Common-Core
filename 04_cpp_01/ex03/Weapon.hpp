/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 14:12:35 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/10 17:00:09 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <iostream>

class Weapon
{
	private:
		std::string _type;
	
	public:
		Weapon(void);
		Weapon(std::string const& type);
		~Weapon(void);
		
		std::string&	getType(void);
		void			setType(std::string const& new_type);
};

#endif
