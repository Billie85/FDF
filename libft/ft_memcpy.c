/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:18:06 by root              #+#    #+#             */
/*   Updated: 2022/08/29 22:18:07 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dd;
	unsigned char		*ss;

	if (!src && !dest)
		return (NULL);
	dd = (unsigned char *)dest;
	ss = (unsigned char *)src;
	while (n--)
	{
		*dd++ = *ss++;
	}
	return (dest);
}
