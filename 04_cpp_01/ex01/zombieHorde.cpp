/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 16:17:57 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/07 16:43:02 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *new_elem = new Zombie[N];
	int	i = 0;

	while (i < N)
	{
		new_elem[i].set_name(name);
		i++;
	}

    return (new_elem);
}
