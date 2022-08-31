/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:17:49 by root              #+#    #+#             */
/*   Updated: 2022/08/29 22:17:50 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*head;

	if (!lst || !f)
		return (NULL);
	temp = ft_lstnew((*f)(lst->content));
	if (!temp)
		return (NULL);
	head = temp;
	lst = lst->next;
	while (lst)
	{
		temp -> next = ft_lstnew(f(lst->content));
		if (!temp->next)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		lst = lst->next;
		temp = temp->next;
	}
	return (head);
}
