/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:14:51 by acohaut           #+#    #+#             */
/*   Updated: 2025/11/03 17:14:52 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	free (*lst);
	*lst = NULL;
}
/*
#include <stdio.h>

int		main(void)
{
	t_list *elem = ft_lstnew("Salut");
	printf("elem.content = %s\n", (char *)elem->content);
	printf("elem.next = %s\n", (char *)elem->next);
	return (0);
}*/
