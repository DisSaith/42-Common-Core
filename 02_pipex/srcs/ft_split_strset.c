/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_strset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 20:41:51 by acohaut           #+#    #+#             */
/*   Updated: 2025/12/08 19:02:11 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	is_strset(char c, char *strset)
{
	int	i;

	i = 0;
	while (strset[i])
	{
		if (c == strset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_words_strset(char *str, char *strset)
{
	int	i;
	int	count;
	int	in_word;

	i = 0;
	count = 0;
	in_word = 0;
	while (str[i])
	{
		if (!is_strset(str[i], strset))
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

int	ft_strlen_strset(char *str, char *strset)
{
	int	i;

	i = 0;
	while (str[i] && !is_strset(str[i], strset))
		i++;
	return (i);
}

char	*ft_filltab_strset(char *str, char *strset)
{
	char	*tab;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	tab = malloc(sizeof(char) * (ft_strlen_strset(str, strset) + 1));
	if (!tab)
		return (NULL);
	while (str[i] && !is_strset(str[i], strset))
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	**ft_split_strset(char *s, char *strset)
{
	char	**tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tab = malloc(sizeof(char *) * (count_words_strset(s, strset) + 1));
	if (!tab)
		return (NULL);
	while (s[i])
	{
		while (s[i] && is_strset(s[i], strset))
			i++;
		if (s[i] && !is_strset(s[i], strset))
		{
			tab[j] = ft_filltab_strset(&s[i], strset);
			if (!tab[j])
				return (free_splited(tab));
			j++;
			while (s[i] && !is_strset(s[i], strset))
				i++;
		}
	}
	tab[j] = NULL;
	return (tab);
}
