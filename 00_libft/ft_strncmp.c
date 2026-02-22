/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 16:13:46 by acohaut           #+#    #+#             */
/*   Updated: 2025/11/03 18:04:39 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] == s2[i]) && s1[i] && (i < n - 1))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("val_mine = %d\n", ft_strncmp("SLT", "SLTq", 10));
	printf("val_strcmp = %d\n", strncmp("SLT", "SLTq", 10));
	printf("val_mine = %d\n", ft_strncmp("test", "TEST", 6));
	printf("val_strcmp = %d\n", strncmp("test", "TEST", 6));
	printf("val_mine = %d\n", ft_strncmp("123", "321", 0));
	printf("val_strcmp = %d\n", strncmp("123", "321", 0));
	return (0);
}*/
