/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:05:10 by acohaut           #+#    #+#             */
/*   Updated: 2025/11/03 18:05:17 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c += 32);
	return (c);
}
/*
#include <ctype.h>
#include <stdio.h>

int     main(void)
{
    printf("(ft_func) %c to lowercase -> %c\n", 'A', ft_tolower('A'));
    printf("(real_func) %c to lowercase -> %c\n", 'A', tolower('A'));
    printf("(ft_func) %c to lowercase -> %c\n", 'Z', ft_tolower('Z'));
    printf("(real_func) %c to lowercase -> %c\n", 'Z', tolower('Z'));
    printf("(ft_func) %c to lowercase -> %c\n", 'f', ft_tolower('f'));
    printf("(real_func) %c to lowercase -> %c\n", 'f', tolower('f'));
    return(0);
}*/
