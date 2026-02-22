/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:14:40 by acohaut           #+#    #+#             */
/*   Updated: 2025/11/03 17:14:43 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
#include <stdio.h>

int		main(void)
{
	t_list *elem = ft_lstnew("Salut");
	t_list *elem2 = ft_lstnew("Yolo");
	t_list *elem3 = ft_lstnew("Ciao");
	ft_lstadd_front(&elem, elem2);
	ft_lstadd_front(&elem, elem3);
	
	t_list *current;
	current = elem;
	while (current)
	{
		printf("elem.content = %s\n", (char *)current->content);
		current = current->next;
	}
	return (0);
}*/
