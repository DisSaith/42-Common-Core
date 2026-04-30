/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 16:18:39 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/08 14:15:14 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main (void)
{
    randomChump("Colin");
    Zombie *francis = newZombie("new_Francis");
    Zombie *hubert = newZombie("new_Hubert");
    francis->annonce();
    randomChump("Hugues");
    hubert->annonce();
    delete hubert;
    delete francis;
    return(0);
}
