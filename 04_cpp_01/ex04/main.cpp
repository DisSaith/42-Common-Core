/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 10:23:42 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/10 17:10:55 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"

int	main(int ac, char **av)
{
	File	file;

	if (ac != 4 || File::check_parameters(av) == false)
	{
		std::cerr << "Usage: ./replace filename string1 string2" << std::endl;
		return (1);
	}
	file.initialisation(av[1], av[2], av[3]);
	file.copy_and_replace();
	return (0);
}
