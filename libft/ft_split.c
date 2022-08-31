/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:18:30 by root              #+#    #+#             */
/*   Updated: 2022/08/29 22:18:31 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(const char *str, char c)
{
	size_t	i;
	size_t	v;

	i = 0;
	v = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			v++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
	}
	return (v);
}

static size_t	ft_strup(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

static char	**ft_clear(char **str, size_t n)
{
	while (n--)
		free(str[n]);
	free(str);
	return (NULL);
}

static char	**ssplit(char **res, const char *str, size_t col, const char c)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = -1;
	while (++j < col)
	{
		while (str[i] == c)
			i++;
		len = ft_strup(str + i, c);
		res[j] = ft_substr(str + i, 0, len);
		if (res[j] == NULL)
			return (ft_clear(res, j));
		i += len;
	}
	res[j] = NULL;
	return (res);
}

char	**ft_split(char const *str, char c)
{
	char	**ss;
	size_t	count;

	if (!str)
		return (NULL);
	count = ft_word_count(str, c);
	ss = (char **)malloc(sizeof(char *) * (count + 1));
	if (!ss)
		return (NULL);
	return (ssplit(ss, str, count, c));
}
