/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggiquiau <ggiquiau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 13:18:28 by ggiquiau          #+#    #+#             */
/*   Updated: 2020/11/26 22:59:08 by ggiquiau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*tmp;

	map = NULL;
	while (lst)
	{
		if (!map)
		{
			map = ft_lstnew(f(lst->content));
			tmp = map;
		}
		else
		{
			tmp->next = ft_lstnew(f(lst->content));
			tmp = tmp->next;
		}
		if (!tmp)
		{
			ft_lstclear(&map, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (map);
}
