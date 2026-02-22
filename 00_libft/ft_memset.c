/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:16:41 by acohaut           #+#    #+#             */
/*   Updated: 2025/11/03 17:16:43 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (b);
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
	ft_memset(array, 0, size_array);	
	for (int i = 0 ; i < 6 ; i++)
		printf("(apres) array[%d] = %d\n", i, array[i]);	
    return(0);
}*/
