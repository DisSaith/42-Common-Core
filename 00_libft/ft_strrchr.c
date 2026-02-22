/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:04:49 by acohaut           #+#    #+#             */
/*   Updated: 2025/11/03 18:04:51 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*find;

	find = NULL;
	i = 0;
	while (s[i])
	{
		if ((char)c == s[i])
			find = (char *)&s[i];
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (find);
}
/*
#include <string.h>
#include <stdio.h>

int     main(void)
{
    const char *str = "Salut la compagnie du camembert";
	printf("real_return = %s\n", strrchr(str, 'e'));
	printf("ft_return = %s\n", ft_strrchr(str, 'e'));
    return(0);
}*/
