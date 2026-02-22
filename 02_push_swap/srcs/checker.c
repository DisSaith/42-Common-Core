/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 10:19:55 by acohaut           #+#    #+#             */
/*   Updated: 2025/12/04 11:13:57 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack *list)
{
	t_stack		*current;

	current = list;
	while (current && current->next)
	{
		if (current->nb > current->next->nb)
			return (0);
		current = current->next;
	}
	return (1);
}

int	is_integer(char *str)
{
	int		i;

	if (!str || !str[0])
		return (0);
	i = 0;
	if (str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	check_inputs(t_stack *list, char *str)
{
	t_stack		*current;
	long		nb;

	if (!str || !*str)
		return (0);
	nb = atoi_push_swap(str);
	if (nb < INT_MIN || nb > INT_MAX)
		return (0);
	if (!(is_integer(str)))
		return (0);
	current = list;
	while (current)
	{
		if (current->nb == nb)
			return (0);
		current = current->next;
	}
	return (1);
}
