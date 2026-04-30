/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:40:33 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/21 20:28:16 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main( void )
{
	ClapTrap	xavier( "Xavier", 10, 10, 0 );
	DiamondTrap	jules( "Jules" );
	jules.whoAmI();
	jules.guardGate();
	jules.highFivesGuys();
	jules.attack( "Toto" );
	xavier.takeDamage( 30 );
	return (0);
}