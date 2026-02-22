/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:03:28 by acohaut           #+#    #+#             */
/*   Updated: 2025/11/03 18:03:29 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if ((char)c == s[i])
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
/*
#include <string.h>
#include <stdio.h>

int     main(void)
{
    const char *str = "Salut la compagnie";
	printf("real_return = %s\n", strchr(str, 'k'));
	printf("ft_return = %s\n", ft_strchr(str, 'k'));
    return(0);
}*/
