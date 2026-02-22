/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:14:32 by acohaut           #+#    #+#             */
/*   Updated: 2025/11/03 17:14:35 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next)
		current = current->next;
	current->next = new;
}
/*
#include <stdio.h>

int		main(void)
{
	t_list *elem = ft_lstnew("Salut");
	t_list *elem2 = ft_lstnew("Yolo");
	t_list *elem3 = ft_lstnew("Ciao");
	t_list *elem4 = ft_lstnew("Pouf");
	ft_lstadd_front(&elem, elem2);
	ft_lstadd_front(&elem, elem3);
	ft_lstadd_back(&elem, elem4);
	
	t_list *current;
	current = elem;
	while (current)
	{
		printf("elem.content = %s\n", (char *)current->content);
		current = current->next;
	}
	return (0);
}*/
