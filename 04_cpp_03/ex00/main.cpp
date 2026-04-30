/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 13:40:33 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/21 14:22:52 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap	robert( "Robert" );
	ClapTrap	xavier( "Xavier" );
	robert.attack( "Xavier" );
	xavier.takeDamage( 0 );
	xavier.beRepaired( 10 );
	return (0);
}
