/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 20:41:51 by acohaut           #+#    #+#             */
/*   Updated: 2025/11/03 18:03:23 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_charset(char letter, char charset)
{
	if (letter == charset)
		return (1);
	return (0);
}

int	ft_count_words(char const *str, char c)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (str[i])
	{
		if (!is_charset(str[i], c))
		{
			if (in_word == 0)
			{
				count++;
				in_word = 1;
			}
		}
		else
			in_word = 0;
		i++;
	}
	return (count);
}

int	ft_strlen_split(char const *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && !(is_charset(str[i], c)))
		i++;
	return (i);
}

char	*ft_filltab(char const *str, char c)
{
	char	*tab;
	int		i;

	i = 0;
	tab = malloc(sizeof(char) * (ft_strlen_split(str, c) + 1));
	if (!tab)
		return (NULL);
	while (str[i] && !(is_charset(str[i], c)))
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	while (s[i])
	{
		while (s[i] && is_charset(s[i], c))
			i++;
		if (s[i] && !is_charset(s[i], c))
		{
			tab[j] = ft_filltab(&s[i], c);
			j++;
			while (s[i] && !is_charset(s[i], c))
				i++;
		}
	}
	tab[j] = NULL;
	return (tab);
}
/*
#include <stdio.h>

int	main(void)
{
	char *str = "Salut, le monde : hehe ; Aix-en-Provence";
	char charset = ' ';
	int count = ft_count_words(str, charset);
	printf("count = %d\n", count);
	char **tab = ft_split(str, charset);
	for (int i = 0 ; i < 8 ; i++)
		printf("tab[%d] = %s\n", i, tab[i]);
	free (tab);
	return (0);
}*/
