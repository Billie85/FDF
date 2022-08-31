/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:19:09 by root              #+#    #+#             */
/*   Updated: 2022/09/01 01:00:52 by kayumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	str;

	i = 0;
	str = ft_strlen(src);
	if ((!dst && !src) || !size)
		return (ft_strlen(src));
	while (src[i] && size - 1 > i)
	{	
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (str);
}
