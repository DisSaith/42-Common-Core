/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:13:19 by acohaut           #+#    #+#             */
/*   Updated: 2025/11/03 17:13:24 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = (unsigned char)0;
		i++;
	}
}
/*
#include <stdio.h>
#include <string.h>

int     main(void)
{
	int	array[] = {10, 20, 34, 46, 42, 68};
	for (int i = 0 ; i < 6 ; i++)
		printf("(avant) array[%d] = %d\n", i, array[i]);
	size_t size_array = sizeof(int) * 3;
	ft_bzero(array, size_array);	
	for (int i = 0 ; i < 6 ; i++)
		printf("(apres) array[%d] = %d\n", i, array[i]);	
    return(0);
}*/
