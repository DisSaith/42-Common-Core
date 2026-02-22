/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:41:02 by acohaut           #+#    #+#             */
/*   Updated: 2025/11/03 17:14:05 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("(ft_func) return = %d\n", ft_isascii('z'));
	printf("(real_func) return = %d\n", isascii('z'));
	printf("(ft_func) return = %d\n", ft_isascii('9'));
	printf("(real_func) return = %d\n", isascii('9'));
	printf("(ft_func) return = %d\n", ft_isascii(128));
	printf("(real_func) return = %d\n", isascii(128));
	printf("(ft_func) return = %d\n", ft_isascii(255));
	printf("(real_func) return = %d\n", isascii(255));
	return (0);
}*/
