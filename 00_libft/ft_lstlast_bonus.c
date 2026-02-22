/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:15:37 by acohaut           #+#    #+#             */
/*   Updated: 2025/11/03 17:15:39 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
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
	
	t_list	*last = ft_lstlast(elem);
	printf("last->content = %s\n", (char *)last->content);
	return (0);
}*/
