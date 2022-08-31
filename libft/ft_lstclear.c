/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:17:36 by root              #+#    #+#             */
/*   Updated: 2022/08/29 22:17:37 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*v;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	v = *lst;
	while (v)
	{
		tmp = v -> next;
		ft_lstdelone(v, del);
		v = tmp;
	}
	*lst = NULL;
}
