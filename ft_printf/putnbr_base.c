/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayumi <kayumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:51:14 by kayumi            #+#    #+#             */
/*   Updated: 2022/01/02 19:39:16 by kayumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	putnbr_base(unsigned long long n, char *base)
{
	size_t						len;
	unsigned long long			b;
	unsigned long long			e;

	b = ft_strlen(base);
	if (b < 2)
		return (0);
	len = 0;
	e = 1;
	while (e <= n / b)
		e *= b;
	while (e > 0)
	{
		len += write(1, &base[n / e % b], 1);
		e /= b;
	}
	return (len);
}
