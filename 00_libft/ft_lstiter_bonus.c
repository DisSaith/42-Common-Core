/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:15:32 by acohaut           #+#    #+#             */
/*   Updated: 2025/11/03 17:15:34 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	ft_lower(void *content)
{
	int		i;

	i = 0;
	while (((char *)content)[i])
	{
		((char *)content)[i] += 32;
		i++;
	}
}
*/

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;

	current = lst;
	while (current)
	{
		(*f)(current->content);
		current = current->next;
	}
}
/*
#include <stdio.h>

int		main(void)
{
	t_list *elem1 = ft_lstnew(ft_strdup("SALUT"));
	t_list *elem2 = ft_lstnew(ft_strdup("YOLO"));
	t_list *elem3 = ft_lstnew(ft_strdup("CIAO"));
	ft_lstadd_back(&elem1, elem2);
	ft_lstadd_back(&elem1, elem3);

	t_list *current = elem1;
	for (int i = 0 ; i < 3 ; i++)
	{
		printf("(avant) elem[%d]->content = %s\n",
		i, (char *)current->content);
		current = current->next;
	}
	printf("\n");
	ft_lstiter(elem1, &ft_lower);
	t_list *current2 = elem1;
	for (int i = 0 ; i < 3 ; i++)
	{
		printf("(après) elem[%d]->content = %s\n",
		i, (char *)current2->content);
		current2 = current2->next;
	}
	return (0);
}*/
