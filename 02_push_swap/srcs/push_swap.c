/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 10:20:20 by acohaut           #+#    #+#             */
/*   Updated: 2025/12/04 11:18:42 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	parsing_arg(t_stack **stack_a, int argc, char *argv[])
{
	int		i;

	i = 0;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		i = -1;
	}
	if (!argv[i + 1])
		return (display_error(argc, argv, 1));
	while (argv && argv[i + 1] != NULL)
	{
		if (!*argv[i + 1])
			return (display_error(argc, argv, 1));
		if (!(check_inputs(*stack_a, argv[i + 1])))
			return (display_error(argc, argv, 1));
		lstadd_back(stack_a, atoi_push_swap(argv[i + 1]), -1);
		i++;
	}
	if (argc == 2)
		return (display_error(argc, argv, 0));
	return (1);
}

void	choosing_sorting(t_stack **stack_a, t_stack **stack_b)
{
	long	size;

	size = lstsize(*stack_a);
	if (size == 2)
	{
		if ((*stack_a)->index > (*stack_a)->next->index)
			swap(stack_a, stack_a, "sa");
	}
	else if (size == 3)
		sorting_three(stack_a);
	else if (size <= 5)
		sorting_max_five(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

int	main(int argc, char *argv[])
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	if (argc <= 1)
		return (1);
	stack_a = NULL;
	stack_b = NULL;
	if (!parsing_arg(&stack_a, argc, argv))
	{
		lstclear(&stack_a);
		lstclear(&stack_b);
		return (1);
	}
	if (is_sorted(stack_a))
	{
		lstclear(&stack_a);
		lstclear(&stack_b);
		return (0);
	}
	give_index(&stack_a);
	choosing_sorting(&stack_a, &stack_b);
	lstclear(&stack_a);
	lstclear(&stack_b);
	return (0);
}
