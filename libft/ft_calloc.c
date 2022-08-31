/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:17:01 by root              #+#    #+#             */
/*   Updated: 2022/09/01 01:01:30 by kayumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*h;

	if (!n || !size)
	{
		n = 1;
		size = 1;
	}
	else if (n > ((size_t) - 1) / size)
		return (NULL);
	h = malloc(n * size);
	if (h == NULL)
		return (NULL);
	ft_bzero(h, size * n);
	return (h);
}
