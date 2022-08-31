/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:19:23 by root              #+#    #+#             */
/*   Updated: 2022/08/29 22:19:24 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *find, size_t len)
{
	size_t	str;

	str = ft_strlen(find);
	if (*find == '\0')
		return ((char *) big);
	while (*big != '\0' && len >= str)
	{
		if (ft_strncmp(big, find, str) == 0)
			return ((char *) big);
		big++;
		len--;
	}
	return (NULL);
}
