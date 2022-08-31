/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:18:46 by root              #+#    #+#             */
/*   Updated: 2022/09/01 01:01:13 by kayumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	size_dst;
	size_t	size_src;
	size_t	size_total;
	size_t	len;
	size_t	i;

	i = 0;
	size_src = ft_strlen(src);
	size_dst = ft_strlen(dst);
	size_total = size_dst + size_src;
	len = size - size_dst - 1;
	if (size_dst < size)
	{
		while (src[i] && i < len)
		{
			dst[size_dst++] = src[i++];
			dst[size_dst] = '\0';
		}
		return (size_total);
	}
	return (size_src + size);
}
