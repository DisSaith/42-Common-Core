/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 16:57:45 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/10 16:57:47 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) : _name("")
{
	std::cout << "new zombie created, which currently has no name." << std::endl;
    return ;
}

Zombie::Zombie(std::string name) : _name(name)
{
    std::cout << _name << ": created." << std::endl;
    return ;
}

void	Zombie::set_name(std::string new_name)
{
	_name = new_name;
	std::cout << "setting name \"" << new_name << "\" to an unnamed zombie." << std::endl;
}

void	Zombie::annonce(void)
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << _name << ": destroyed." << std::endl;
    return ;
}
