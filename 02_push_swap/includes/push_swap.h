/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 10:19:20 by acohaut           #+#    #+#             */
/*   Updated: 2025/12/04 10:19:45 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

/***************CHAINED LIST***************/
typedef struct s_stack
{
	long			nb;
	long			index;
	struct s_stack	*next;
}					t_stack;

t_stack		*lstnew_elem(long nb, long index);
t_stack		*find_min(t_stack *stack_a);
long		lstsize(t_stack *list);
void		give_index(t_stack **stack_a);
void		lstadd_back(t_stack **list, long nb, long index);
void		lstadd_front(t_stack **list, long nb, long index);
void		lstdel_head(t_stack **list);
void		lstclear(t_stack **list);

/***************OPERATIONS***************/
void		swap(t_stack **stack_a, t_stack **stack_b, char *oper);
void		push(t_stack **stack_a, t_stack **stack_b, char *oper);
void		shift_up(t_stack **stack_a, t_stack **stack_b, char *oper);
void		shift_down(t_stack **list, char *oper);
void		shift_d_both(t_stack **stack_a, t_stack **stack_b, char *oper);

/***************SORTING***************/
long		find_min_position(t_stack *list);
long		get_max_bits(long max_num);
void		sorting_three(t_stack **a);
void		sorting_max_five(t_stack **a, t_stack **b);
void		radix_sort(t_stack **a, t_stack **b);

/***************UTILS***************/
long		atoi_push_swap(char *str);
int			strlength(char *str);
int			is_sorted(t_stack *list);
int			is_integer(char *str);
int			check_inputs(t_stack *list, char *str);
int			parsing_arg(t_stack **stack_a, int argc, char *argv[]);
int			display_error(int argc, char *argv[], int error);
void		display_operation(char *str);
void		choosing_sorting(t_stack **stack_a, t_stack **stack_b);

#endif
