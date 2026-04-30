/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 15:35:40 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/08 17:31:00 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main(void)
{
	Weapon club1 = Weapon("crude spiked club");
	std::cout << std::endl;
	HumanA bob("Bob", club1);
	bob.attack();
	club1.setType("some other type of club");
	bob.attack();

	std::cout << std::endl << std::endl;
	Weapon club2 = Weapon("crude spiked club");
	std::cout << std::endl;
	HumanB jim("Jim");
	jim.attack();
	jim.setWeapon(club2);
	jim.attack();
	club2.setType("some other type of club");
	jim.attack();
	std::cout << std::endl;
	return 0;
}
