/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:42:40 by acohaut           #+#    #+#             */
/*   Updated: 2025/11/17 14:38:17 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	size_t	i;

	if (!dest || !src)
		return (NULL);
	if (dest == src)
		return (dest);
	else if (dest > src)
	{
		i = size;
		while (i > 0)
		{
			i--;
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		}
	}
	else if (dest < src)
	{
		i = 0;
		while (i < size)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

char	*ft_strchr_gnl(char *str, char c, char **tmp)
{
	size_t	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			*tmp = &str[i];
			return (&str[i]);
		}
		i++;
	}
	*tmp = NULL;
	return (NULL);
}

int	ft_strjoin_gnl(char **s1, char *s2, size_t size2)
{
	size_t	size1;
	char	*join;

	size1 = ft_strlen(*s1);
	join = malloc(sizeof(char) * (size1 + size2 + 1));
	if (!join)
		return (0);
	if (*s1)
		ft_memcpy(join, *s1, size1);
	ft_memcpy(join + size1, s2, size2);
	join[size1 + size2] = '\0';
	if (*s1)
		free(*s1);
	*s1 = join;
	return (1);
}
