/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 10:20:25 by acohaut           #+#    #+#             */
/*   Updated: 2025/12/04 10:20:27 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long	find_min_position(t_stack *list)
{
	t_stack		*current;
	long		min_pos;
	long		min_value;
	long		pos;

	current = list;
	min_pos = 0;
	pos = 0;
	min_value = current->index;
	while (current)
	{
		if (current->index < min_value)
		{
			min_value = current->index;
			min_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (min_pos);
}

void	sorting_three(t_stack **a)
{
	long	first;
	long	second;
	long	third;

	first = (*a)->index;
	second = (*a)->next->index;
	third = (*a)->next->next->index;
	if (first > second && second < third && first < third)
		swap(a, a, "sa");
	else if (first > second && second > third)
	{
		swap(a, a, "sa");
		shift_down(a, "rra");
	}
	else if (first > second && second < third && first > third)
		shift_up(a, a, "ra");
	else if (first < second && second > third && first < third)
	{
		swap(a, a, "sa");
		shift_up(a, a, "ra");
	}
	else if (first < second && second > third && first > third)
		shift_down(a, "rra");
}

void	sorting_max_five(t_stack **a, t_stack **b)
{
	long	size;
	long	min_pos;

	size = lstsize(*a);
	while (size > 3)
	{
		min_pos = find_min_position(*a);
		if (min_pos <= size / 2)
			while (min_pos-- > 0)
				shift_up(a, a, "ra");
		else
			while (min_pos++ < size)
				shift_down(a, "rra");
		push(a, b, "pb");
		size--;
	}
	if (size == 3)
		sorting_three(a);
	else if (size == 2 && (*a)->index > (*a)->next->index)
		swap(a, a, "sa");
	while (*b)
		push(a, b, "pa");
}

long	get_max_bits(long max_num)
{
	long	bits;

	bits = 0;
	while (max_num > 0)
	{
		max_num >>= 1;
		bits++;
	}
	return (bits);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	long	max_bits;
	long	size;
	long	i;
	long	j;

	size = lstsize(*a);
	max_bits = get_max_bits(size - 1);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if ((((*a)->index >> i) & 1) == 0)
				push(a, b, "pb");
			else
				shift_up(a, a, "ra");
			j++;
		}
		while (*b)
			push(a, b, "pa");
		if (is_sorted(*a) && !*b)
			return ;
		i++;
	}
}
