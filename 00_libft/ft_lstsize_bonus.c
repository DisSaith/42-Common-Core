/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:16:00 by acohaut           #+#    #+#             */
/*   Updated: 2025/11/03 17:16:01 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*current;

	i = 0;
	current = lst;
	while (current)
	{
		i++;
		current = current->next;
	}
	return (i);
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
	
	int	size = ft_lstsize(elem);
	printf("list size = %d\n", size);
	return (0);
}*/
