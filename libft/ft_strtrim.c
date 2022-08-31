/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:19:30 by root              #+#    #+#             */
/*   Updated: 2022/08/29 22:19:31 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	unsigned int	ft_charset(char c, char const *charset)
{
	size_t	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*str;
	size_t		start;
	size_t		goal;
	size_t		i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_charset(s1[start], set))
		start++;
	goal = ft_strlen(s1);
	while (goal > start && ft_charset(s1[goal - 1], set))
		goal--;
	str = (char *)malloc(sizeof(*s1) * (goal - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < goal)
		str[i++] = s1[start++];
	str[i] = 0;
	return (str);
}
