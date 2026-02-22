/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:41:02 by acohaut           #+#    #+#             */
/*   Updated: 2025/11/03 17:14:13 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("(ft_func) return = %d\n", ft_isdigit('0'));
	printf("(real_func) return = %d\n", isdigit('0'));
	printf("(ft_func) return = %d\n", ft_isdigit('9'));
	printf("(real_func) return = %d\n", isdigit('9'));
	printf("(ft_func) return = %d\n", ft_isdigit('A'));
	printf("(real_func) return = %d\n", isdigit('A'));
	printf("(ft_func) return = %d\n", ft_isdigit('a'));
	printf("(real_func) return = %d\n", isdigit('a'));
	printf("(ft_func) return = %d\n", ft_isdigit('1'));
	printf("(real_func) return = %d\n", isdigit('1'));
	return (0);
}*/
