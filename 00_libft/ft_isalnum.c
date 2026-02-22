/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:41:02 by acohaut           #+#    #+#             */
/*   Updated: 2025/11/03 17:13:48 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)
		|| (c >= 48 && c <= 57))
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("(ft_func) return = %d\n", ft_isalnum('$'));
	printf("(real_func) return = %d\n", isalnum('$'));
	printf("(ft_func) return = %d\n", ft_isalnum('Z'));
	printf("(real_func) return = %d\n", isalnum('Z'));
	printf("(ft_func) return = %d\n", ft_isalnum('9'));
	printf("(real_func) return = %d\n", isalnum('9'));
	printf("(ft_func) return = %d\n", ft_isalnum('a'));
	printf("(real_func) return = %d\n", isalnum('a'));
	printf("(ft_func) return = %d\n", ft_isalnum('0'));
	printf("(real_func) return = %d\n", isalnum('0'));
	return (0);
}*/
