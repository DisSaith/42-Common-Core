/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:15:54 by acohaut           #+#    #+#             */
/*   Updated: 2025/11/03 17:15:55 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nw_elem;

	nw_elem = malloc(sizeof(t_list));
	if (!nw_elem)
		return (NULL);
	nw_elem->content = content;
	nw_elem->next = NULL;
	return (nw_elem);
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
