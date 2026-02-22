/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acohaut <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:15:46 by acohaut           #+#    #+#             */
/*   Updated: 2025/11/03 18:14:17 by acohaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void	*ft_lower(void *content)
{
	char *str = (char *)content;
    char *new_str = ft_strdup(str);
    int i = 0;

    if (!new_str)
        return (NULL);
    while (new_str[i])
    {
        if (new_str[i] >= 'A' && new_str[i] <= 'Z')
            new_str[i] += 32;
        i++;
    }
    return (new_str);
}

void	ft_del(void *content)
{
	free (content);
}*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nw_list;
	t_list	*nw_content;

	if (!lst || !f || !del)
		return (NULL);
	nw_list = NULL;
	while (lst)
	{
		nw_content = ft_lstnew((*f)(lst->content));
		if (!nw_content)
		{
			ft_lstclear(&nw_list, del);
			return (NULL);
		}
		ft_lstadd_back(&nw_list, nw_content);
		lst = lst->next;
	}
	return (nw_list);
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
	t_list *nw_list = ft_lstmap(elem1, &ft_lower, &ft_del);
	t_list *tmp = nw_list;
	int i = 0;
	while (tmp)
	{
		printf("(après) elem[%d]->content = %s\n",
		i, (char *)tmp->content);
		tmp = tmp->next;
		i++;
	}
	return (0);
}*/
