/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:17:59 by root              #+#    #+#             */
/*   Updated: 2022/08/29 22:18:00 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	cc1;

	ss1 = (unsigned char *)s;
	cc1 = (unsigned char)c;
	i = 0;
	while (i++ < n)
	{
		if (*ss1 == cc1)
		{
			return (ss1);
		}
		ss1++;
	}
	return (NULL);
}
