/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:05:21 by acohaut           #+#    #+#             */
/*   Updated: 2025/11/03 18:05:23 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c -= 32);
	return (c);
}
/*
#include <ctype.h>
#include <stdio.h>

int     main(void)
{
    printf("(ft_func) %c to uppercase -> %c\n", 'a', ft_toupper('a'));
    printf("(real_func) %c to uppercase -> %c\n", 'a', toupper('a'));
    printf("(ft_func) %c to uppercase -> %c\n", 'z', ft_toupper('z'));
    printf("(real_func) %c to uppercase -> %c\n", 'z', toupper('z'));
    printf("(ft_func) %c to uppercase -> %c\n", 'F', ft_toupper('F'));
    printf("(real_func) %c to uppercase -> %c\n", 'F', toupper('F'));
    return(0);
}*/
