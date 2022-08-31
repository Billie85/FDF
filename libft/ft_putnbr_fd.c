/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:18:23 by root              #+#    #+#             */
/*   Updated: 2022/08/29 22:18:24 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	str;

	str = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		str = str * -1;
	}
	if (str >= 10)
	{
		ft_putnbr_fd(str / 10, fd);
		str = str % 10;
	}
	if (str < 10)
	{
		ft_putchar_fd('0' + str, fd);
	}
}
