/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 16:17:52 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/07 17:02:13 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main (void)
{
	int	const tab_max = 5;
	Zombie *tab = zombieHorde(tab_max, "Pierre");
	Zombie *tab2 = zombieHorde(1, "Arthur");
	for (int i = 0 ; i < tab_max ; i++)
		tab[i].annonce();
	tab2[0].annonce();
	delete [] tab;
	delete [] tab2;
    return(0);
}
