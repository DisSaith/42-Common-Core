/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:02:32 by acohaut           #+#    #+#             */
/*   Updated: 2025/11/03 18:04:01 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	if (dstsize < 1)
		return (len);
	while (i < (dstsize - 1) && src[i] != 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	src[] = "Coucou ma biche";
	char	dst[] = "Ca va ?";
	size_t	size_src;
	printf("(avant) src = %s\n", src);
	printf("(avant) dest = %s\n", dst);
	size_src = ft_strlcpy(dst, src, sizeof(dst));
	printf("size_src = %zu\n", size_src);
	printf("(apres) dest = %s\n", dst);
	//ajouter flag -lbsd
	return (0);
}*/
