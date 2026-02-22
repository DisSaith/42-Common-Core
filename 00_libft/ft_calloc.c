/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 19:19:37 by acohaut           #+#    #+#             */
/*   Updated: 2025/11/03 17:13:35 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*memory;
	size_t	i;

	i = 0;
	memory = malloc(size * count);
	if (!memory)
		return (NULL);
	while (i < (count * size))
	{
		((unsigned char *)memory)[i] = (unsigned char)0;
		i++;
	}
	return (memory);
}
/*
#include <stdio.h>

int	main(void)
{
	int *arr;
    size_t i;
    arr = ft_calloc(5, sizeof(int));
    if (!arr)
        return (1);
    for (i = 0; i < 5; i++)
        printf("%d ", arr[i]); // doit afficher : 0 0 0 0 0
    free(arr);
    return (0);
}*/
