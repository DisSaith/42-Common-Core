/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 16:32:13 by acohaut           #+#    #+#             */
/*   Updated: 2025/11/03 17:13:10 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	atoi;
	int	sign;
	int	i;

	sign = 1;
	atoi = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		atoi *= 10;
		atoi += str[i] - 48;
		i++;
	}
	return (atoi * sign);
}
/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char *str1 = "   --1234ab567";
	char *str2 = "   -+1234ab567";
	char *str3 = "   -1234ab567";
	printf("(real_func) return = %d\n", atoi(str1));
	printf("(ft_func) return = %d\n", ft_atoi(str1));
	printf("(real_func) return = %d\n", atoi(str2));
	printf("(ft_func) return = %d\n", ft_atoi(str2));
	printf("(real_func) return = %d\n", atoi(str3));
	printf("(ft_func) return = %d\n", ft_atoi(str3));
	return (0);
}*/
