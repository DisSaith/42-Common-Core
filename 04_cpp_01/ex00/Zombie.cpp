/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 16:18:52 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/07 17:09:10 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) : _name("")
{
    std::cout << "new zombie created withoud a name" << std::endl;
    return ;
}

Zombie::Zombie(std::string name) : _name(name)
{
    std::cout << _name << ": created." << std::endl;
    return ;
}

void Zombie::annonce(void)
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << _name << ": destroyed." << std::endl;
    return ;
}
