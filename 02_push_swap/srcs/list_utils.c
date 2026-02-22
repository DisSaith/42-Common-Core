/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 10:20:09 by acohaut           #+#    #+#             */
/*   Updated: 2025/12/04 10:20:10 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*find_min(t_stack *stack_a)
{
	t_stack		*min;
	t_stack		*current;

	current = stack_a;
	min = NULL;
	while (current)
	{
		if (current->index == -1)
		{
			if (!min || current->nb < min->nb)
				min = current;
		}
		current = current->next;
	}
	return (min);
}

long	lstsize(t_stack *list)
{
	long		size;
	t_stack		*current;

	size = 0;
	current = list;
	while (current)
	{
		size++;
		current = current->next;
	}
	return (size);
}

void	give_index(t_stack **stack_a)
{
	t_stack		*min;
	long		size;
	long		index;

	size = lstsize(*stack_a);
	index = 0;
	while (index < size)
	{
		min = find_min(*stack_a);
		if (min)
			min->index = index;
		index++;
	}
}
