/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:19:26 by root              #+#    #+#             */
/*   Updated: 2022/08/29 22:19:27 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	cc;

	cc = (char) c;
	if (cc == '\0')
		return (ft_strchr(s, '\0'));
	len = ft_strlen(s);
	while (len--)
	{
		if (s[len] == cc)
			return ((char *)&s[len]);
	}
	return (NULL);
}
