/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:40:33 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/21 20:30:23 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main( void )
{
	ClapTrap	xavier( "Xavier", 10, 10, 10 );
	ScavTrap	jojo( "Jojo", 100, 50, 20 );
	ScavTrap	fifi( "Fifi" );
	jojo.attack( "Xavier" );
	xavier.takeDamage( 20 );
	xavier.attack( "Jojo" );
	jojo.guardGate();
	jojo.guardGate();
	jojo.guardGate();
	return (0);
}
