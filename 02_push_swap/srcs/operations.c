/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 10:20:15 by acohaut           #+#    #+#             */
/*   Updated: 2025/12/04 10:20:16 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **stack_a, t_stack **stack_b, char *oper)
{
	t_stack		*first;
	t_stack		*second;

	if (ft_strncmp(oper, "sa", 2) == 0 || ft_strncmp(oper, "ss", 2) == 0)
	{
		if (!*stack_a || !(*stack_a)->next)
			return ;
		first = *stack_a;
		second = first->next;
		first->next = second->next;
		second->next = first;
		*stack_a = second;
	}
	if (ft_strncmp(oper, "sb", 2) == 0 || ft_strncmp(oper, "ss", 2) == 0)
	{
		if (!*stack_b || !(*stack_b)->next)
			return ;
		first = *stack_b;
		second = first->next;
		first->next = second->next;
		second->next = first;
		*stack_b = second;
	}
	display_operation(oper);
}

void	push(t_stack **stack_a, t_stack **stack_b, char *oper)
{
	if (ft_strncmp(oper, "pa", 2) == 0)
	{
		if (!stack_b || !*stack_b)
			return ;
		lstadd_front(stack_a, (*stack_b)->nb, (*stack_b)->index);
		lstdel_head(stack_b);
	}
	if (ft_strncmp(oper, "pb", 2) == 0)
	{
		if (!stack_a || !*stack_a)
			return ;
		lstadd_front(stack_b, (*stack_a)->nb, (*stack_a)->index);
		lstdel_head(stack_a);
	}
	display_operation(oper);
}

void	shift_up(t_stack **stack_a, t_stack **stack_b, char *oper)
{
	if (ft_strncmp(oper, "ra", 2) == 0 || ft_strncmp(oper, "rr", 2) == 0)
	{
		if (!stack_a || !*stack_a)
			return ;
		lstadd_back(stack_a, (*stack_a)->nb, (*stack_a)->index);
		lstdel_head(stack_a);
	}
	if (ft_strncmp(oper, "rb", 2) == 0 || ft_strncmp(oper, "rr", 2) == 0)
	{
		if (!stack_b || !*stack_b)
			return ;
		lstadd_back(stack_b, (*stack_b)->nb, (*stack_b)->index);
		lstdel_head(stack_b);
	}
	display_operation(oper);
}

void	shift_down(t_stack **list, char *oper)
{
	t_stack		*last;
	t_stack		*current;

	if (!list || !*list)
		return ;
	last = *list;
	while (last->next != NULL)
		last = last->next;
	lstadd_front(list, last->nb, last->index);
	current = *list;
	while (current->next != last)
		current = current->next;
	current->next = NULL;
	free(last);
	if (ft_strncmp(oper, "rra", 3) == 0 || ft_strncmp(oper, "rrb", 3) == 0)
		display_operation(oper);
}

void	shift_d_both(t_stack **stack_a, t_stack **stack_b, char *oper)
{
	shift_down(stack_a, "rrr");
	shift_down(stack_b, "rrr");
	display_operation(oper);
}
