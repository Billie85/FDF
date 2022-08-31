/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayumi <kayumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:31:17 by kayumi            #+#    #+#             */
/*   Updated: 2021/12/10 13:31:18 by kayumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr(int n)
{
	size_t	len;

	len = 0;
	if (n == -2147483648)
	{
		return (write(1, "-2147483648", 11));
	}
	if (n < 0)
	{
		len = 1;
		ft_putchar('-');
		n = n * -1;
	}
	len += count_decimal(n);
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		n = n % 10;
	}
	if (0 <= n && n <= 9)
	{
		ft_putchar(n + '0');
	}
	return (len);
}
