/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:41:02 by acohaut           #+#    #+#             */
/*   Updated: 2025/11/03 17:14:18 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("(ft_func) return = %d\n", ft_isprint(19));
	printf("(real_func) return = %d\n", isprint(19));
	printf("(ft_func) return = %d\n", ft_isprint('Z'));
	printf("(real_func) return = %d\n", isprint('Z'));
	printf("(ft_func) return = %d\n", ft_isprint('9'));
	printf("(real_func) return = %d\n", isprint('9'));
	printf("(ft_func) return = %d\n", ft_isprint(127));
	printf("(real_func) return = %d\n", isprint(127));
	return (0);
}*/
