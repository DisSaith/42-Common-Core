/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 13:41:02 by acohaut           #+#    #+#             */
/*   Updated: 2025/11/03 17:13:55 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	printf("(ft_func) return = %d\n", ft_isalpha('z'));
	printf("(real_func) return = %d\n", isalpha('z'));
	printf("(ft_func) return = %d\n", ft_isalpha('Z'));
	printf("(real_func) return = %d\n", isalpha('Z'));
	printf("(ft_func) return = %d\n", ft_isalpha('A'));
	printf("(real_func) return = %d\n", isalpha('A'));
	printf("(ft_func) return = %d\n", ft_isalpha('a'));
	printf("(real_func) return = %d\n", isalpha('a'));
	printf("(ft_func) return = %d\n", ft_isalpha('1'));
	printf("(real_func) return = %d\n", isalpha('1'));
	return (0);
}*/
