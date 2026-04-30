/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 15:44:45 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/09 18:02:33 by acohaut          ###   ########.fr       */
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

	if (level.empty() == true)
	{
		std::cerr << "error: empty parameter" << std::endl;
		return ;
	}
	while (i < 4)
	{
		if (levels[i] == level)
			break ;
		i++;
	}
	switch (i)
	{
		case 0:
			for (int j = i ; j < 4 ; j++)
			{
				std::cout << "[ " << levels[j] << " ]" << std::endl;
				(this->*functions[j])();
				std::cout << std::endl;
			}
			break ;
		case 1:
			for (int j = i ; j < 4 ; j++)
			{
				std::cout << "[ " << levels[j] << " ]" << std::endl;
				(this->*functions[j])();
				std::cout << std::endl;
			}
			break ;
		case 2:
			for (int j = i ; j < 4 ; j++)
			{
				std::cout << "[ " << levels[j] << " ]" << std::endl;
				(this->*functions[j])();
				std::cout << std::endl;
			}
			break ;
		case 3:
			for (int j = i ; j < 4 ; j++)
			{
				std::cout << "[ " << levels[j] << " ]" << std::endl;
				(this->*functions[j])();
				std::cout << std::endl;
			}
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break ;
	}
}
