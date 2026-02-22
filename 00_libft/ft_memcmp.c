/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:16:18 by acohaut           #+#    #+#             */
/*   Updated: 2025/11/03 17:16:20 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return ((int)(str1[i] - str2[i]));
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int     main(void)
{
	//const char	*array1 = "\0";
	//const char	*array2 = "\0";
	const int	array1[] = {10, 20, 34, 46, 42};
	const int	array2[] = {10, 20, 44, 46, 42};
	for (int i = 0 ; i < 5 ; i++)
		printf("array1[%d] = %d\n", i, array1[i]);
	printf("\n");
	for (int i = 0 ; i < 5 ; i++)
		printf("array2[%d] = %d\n", i, array2[i]);
	printf("\n");
	size_t n = sizeof(int) * 3;
	printf("retour memcmp = %d\n", ft_memcmp(array1, array2, n));
    return(0);
}*/
