/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:26:08 by acohaut           #+#    #+#             */
/*   Updated: 2025/11/03 18:03:54 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_d;
	size_t	len_d_start;
	size_t	len_s_start;

	len_d_start = ft_strlen((const char *)dest);
	len_s_start = ft_strlen(src);
	i = 0;
	len_d = ft_strlen((const char *)dest);
	if (dstsize == 0)
		return (len_s_start);
	if (dstsize < len_d)
		return (len_s_start + dstsize);
	while (src[i] && (dstsize - 1) > len_d)
	{
		dest[len_d] = src[i];
		i++;
		len_d++;
	}
	dest[len_d] = '\0';
	return (len_d_start + len_s_start);
}
/*
#include <string.h>
#include <stdio.h>

int		main(void)
{
	char	src[] = "Ca va bg ?";
	char	dest[20] = "Salut. ";
	printf("src = %s\n", src);
	printf("(avant) dest = %s\n", dest);
	size_t size = ft_strlcat(dest, src, 20);
	printf("(apres) dest = %s | size = %zu\n", dest, size);
	//ajouter flag -lbsd pour tester strlcat
}*/
