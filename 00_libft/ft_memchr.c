/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:16:07 by acohaut           #+#    #+#             */
/*   Updated: 2025/11/03 17:16:09 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char)c == ((unsigned char *)s)[i])
			return ((void *)((unsigned char *)s + i));
		i++;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <string.h>

int     main(void)
{
	const int	array[] = {10, 20, 34, 46, 42, 68};
	for (int i = 0 ; i < 6 ; i++)
		printf("array[%d] = %d\n", i, array[i]);
	printf("\n");
	void *retour = ft_memchr(array, 68, 24);
	printf("retour memchr = %d\n", ((int *)retour)[0]);
    return(0);
}*/
