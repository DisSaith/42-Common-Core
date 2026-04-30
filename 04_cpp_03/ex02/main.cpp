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

int	main( void )
{
	ClapTrap	xavier( "Xavier", 10, 10, 10 );
	ScavTrap	arthur( "Arthur" );
	FragTrap	toto( "Toto" );
	xavier.attack( "Toto" );
	toto.takeDamage( 10 );
	xavier.beRepaired( 100 );
	xavier.beRepaired( 100 );
	for (int i = 0 ; i < 10 ; i++)
		toto.highFivesGuys();
	return (0);
}