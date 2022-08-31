/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayumi <kayumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 18:39:36 by kayumi            #+#    #+#             */
/*   Updated: 2022/01/05 20:04:46 by kayumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	another_function(char *max, va_list ap)
{
	size_t	len;

	len = 0;
	if (*max == 'p')
	{
		len += ft_putstr("0x");
		len += putnbr_base(va_arg(ap, unsigned long long), OX);
	}
	if (*max == 'u')
		len += putnbr_base(va_arg(ap, unsigned int), NUM);
	else if (*max == 'x')
		len += putnbr_base(va_arg(ap, unsigned int), OX);
	else if (*max == 'X')
		len += putnbr_base(va_arg(ap, unsigned int), O_X);
	else if (*max == 'd' || *max == 'i')
		len += ft_putnbr(va_arg(ap, int));
	else if (*max == 's')
		len += ft_putstr(va_arg(ap, char *));
	else if (*max == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *s, ...)
{
	char	*max;
	size_t	len;
	va_list	ap;

	max = (char *)s;
	va_start(ap, s);
	len = 0;
	while (*max != '\0')
	{
		if (*max != '%')
			len += ft_output(&max);
		else if (*max == '%')
		{
			max++;
			if (*max == 'c')
				len += ft_putchar((unsigned char)va_arg(ap, int));
			else
				len += another_function(max, ap);
			++max;
		}
		if (len > INT_MAX)
			return (-1);
	}
	va_end(ap);
	return ((int)len);
}
