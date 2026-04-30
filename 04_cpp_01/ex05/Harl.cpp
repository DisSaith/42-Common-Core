/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 15:44:45 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/10 17:13:51 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	return ;
}

Harl::~Harl(void)
{
	return ;
}

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string		levels[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	void			(Harl::*functions[4])(void) = { &Harl::debug, 
													&Harl::info, 
													&Harl::warning,
													&Harl::error };
	int				i = 0;

	while (i < 4)
	{
		if (levels[i] == level)
		{
			std::cout << "[" << levels[i] << "]" << std::endl;
			(this->*functions[i])();
			std::cout << std::endl;
			return ;
		}
		i++;
	}
	std::cerr << "error: invalid level." << std::endl;
}
