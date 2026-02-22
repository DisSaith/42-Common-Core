/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:54:00 by acohaut           #+#    #+#             */
/*   Updated: 2025/11/03 18:04:29 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	const char	*find;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			find = &haystack[i];
			while (haystack[i + j] == needle[j] && needle[j] && ((i + j) < len))
				j++;
			if (needle[j] == '\0')
				return ((char *)find);
		}
		i++;
	}
	return (0);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	str1[] = "Bomjour, tu rarararasputine, ca va ?";
	char	str2[] = "rasputine";
	printf("botte de foin = %s\n", str1);
	printf("aiguille = %s\n", str2);
	char 	*ft_trouve = ft_strnstr(str1, str2, 28);
	char 	*real_trouve = strnstr(str1, str2, 28);
	printf("ft_trouve = %s\n", ft_trouve);
	printf("real_trouve = %s\n", real_trouve);
}*/
