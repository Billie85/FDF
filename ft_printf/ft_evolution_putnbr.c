/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evolution_putnbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayumi <kayumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:31:29 by kayumi            #+#    #+#             */
/*   Updated: 2021/12/10 13:31:30 by kayumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_evolution_putnbr(size_t n)
{
	size_t	len;

	len = count_function(n);
	if (n >= 16)
	{
		ft_evolution_putnbr(n / 16);
		n = n % 16;
	}
	if (0 < n && n < 9)
		ft_putchar (n + '0');
	if (10 <= n && n <= 15)
	{
		n = n - 10 + 'a';
		ft_putchar (n);
	}
	return (len);
}
