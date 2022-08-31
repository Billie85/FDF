/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:17:26 by root              #+#    #+#             */
/*   Updated: 2022/08/29 22:17:27 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_digits(int n)
{
	long	tmp;
	size_t	gis;

	tmp = (long)n;
	if (n < 0)
		tmp *= -1;
	gis = 0;
	while (tmp > 0)
	{
		tmp /= 10;
		gis++;
	}
	if (n <= 0)
		return (gis + 1);
	return (gis);
}

static char	*ft_put(char *str, long n, unsigned int gis)
{
	unsigned int	flag;
	long			tmp;

	tmp = n;
	flag = 0;
	if (n < 0)
	{
		tmp *= -1;
		str[0] = '-';
		flag = 1;
	}
	while (gis > flag)
	{
		str[--gis] = (tmp % 10) + '0';
		tmp /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		gis;
	char	*ans;

	gis = ft_digits(n);
	str = (char *)malloc(sizeof(char) * (gis + 1));
	if (str == NULL)
		return (NULL);
	str[gis] = '\0';
	ans = ft_put(str, n, gis);
	return (ans);
}
