/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 10:20:02 by acohaut           #+#    #+#             */
/*   Updated: 2025/12/04 10:20:04 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*lstnew_elem(long nb, long index)
{
	t_stack		*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->index = index;
	new->next = NULL;
	return (new);
}

void	lstadd_back(t_stack **list, long nb, long index)
{
	t_stack		*current;

	if (!list)
		return ;
	if (!*list)
	{
		*list = lstnew_elem(nb, index);
		return ;
	}
	current = *list;
	while (current->next != NULL)
		current = current->next;
	current->next = lstnew_elem(nb, index);
}

void	lstadd_front(t_stack **list, long nb, long index)
{
	t_stack		*tmp;

	if (!list || !*list)
		return ;
	tmp = *list;
	*list = lstnew_elem(nb, index);
	(*list)->next = tmp;
}

void	lstdel_head(t_stack **list)
{
	t_stack		*del;

	if (!list || !*list)
		return ;
	del = *list;
	*list = (*list)->next;
	free(del);
}

void	lstclear(t_stack **list)
{
	t_stack		*current;
	t_stack		*next;

	if (!list || !*list)
		return ;
	current = *list;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*list = NULL;
}
