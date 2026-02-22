/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:15:23 by acohaut           #+#    #+#             */
/*   Updated: 2025/11/03 17:15:24 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!del || !lst)
		return ;
	(*del)(lst->content);
	free(lst);
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
