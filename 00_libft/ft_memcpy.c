/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:16:27 by acohaut           #+#    #+#             */
/*   Updated: 2025/11/03 17:16:28 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}
/*
#include <stdio.h>
#include <string.h>

int     main(void)
{
	const int	array[] = {10, 20, 34, 46, 42, 68};
	int	dst[6];
	for (int i = 0 ; i < 6 ; i++)
		printf("(avant) array[%d] = %d\n", i, array[i]);
	for (int i = 0 ; i < 6 ; i++)
		printf("(avant) dst[%d] = %d\n", i, dst[i]);	
	size_t size_array = sizeof(int) * 6;
	memcpy(dst, array, size_array);	
	for (int i = 0 ; i < 6 ; i++)
		printf("(apres) dst[%d] = %d\n", i, dst[i]);	
    return(0);
}*/
