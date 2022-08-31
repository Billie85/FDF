/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:18:43 by root              #+#    #+#             */
/*   Updated: 2022/08/29 22:18:44 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char				*ss;
	unsigned int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	ss = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (ss == NULL)
		return (NULL);
	i = 0;
	while (*s1 != 0)
		ss[i++] = *s1++;
	while (*s2 != 0)
		ss[i++] = *s2++;
	ss[i] = 0;
	return (ss);
}
