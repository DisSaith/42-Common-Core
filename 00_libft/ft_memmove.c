/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:16:37 by acohaut           #+#    #+#             */
/*   Updated: 2025/11/03 17:16:38 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	if (dst < src)
	{
		i = 0;
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else if (dst > src)
	{
		while (0 < len)
		{
			len--;
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
		}
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>

int     main(void)
{
	const int	array[] = {10, 20, 34, 46, 42, 68};
	//int	dst[6];
	for (int i = 0 ; i < 6 ; i++)
		printf("(avant) array[%d] = %d\n", i, array[i]);
	//printf("\n");
	//for (int i = 0 ; i < 6 ; i++)
		//printf("(avant) dst[%d] = %d\n", i, dst[i]);
	printf("\n");
	ft_memmove((void *)array + 4, array, 4);
	for (int i = 0 ; i < 6 ; i++)
		printf("(apres) dst[%d] = %d\n", i, array[i]);	
    return(0);
}*/
