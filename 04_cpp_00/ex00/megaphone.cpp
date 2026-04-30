/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 13:57:23 by acohaut           #+#    #+#             */
/*   Updated: 2026/04/03 17:33:21 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

bool	is_lowercase(char &letter)
{
	if (letter >= 'a' && letter <= 'z')
		return (true);
	return (false);
}

int		main(int argc, char *argv[])
{
	int	i = 1;
	int	j;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (argv[i])
		{
			j = 0;
			while (argv[i][j])
			{
				if (is_lowercase(argv[i][j]) == true)
					argv[i][j] -= 32;
				j++;
			}
			std::cout << argv[i];
			i++;
		}
	}
	return (0);
}
