/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgrhnzcn <bgrhnzcn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 21:06:23 by bgrhnzcn          #+#    #+#             */
/*   Updated: 2023/10/17 20:03:42 by bgrhnzcn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*newtemp;

	if (!lst || !del)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (NULL);
	newtemp = new;
	lst = lst->next;
	while (lst)
	{
		newtemp->next = ft_lstnew(f(lst->content));
		if (!(newtemp->next))
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		newtemp = newtemp->next;
		lst = lst->next;
	}
	newtemp->next = NULL;
	return (new);
}
