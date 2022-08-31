/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayumi <kayumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:31:35 by kayumi            #+#    #+#             */
/*   Updated: 2021/12/10 13:31:36 by kayumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	count_decimal(int number)
{
	size_t	i;

	i = 0;
	if (number == 0)
		return (1);
	while (number != 0)
	{
		number = number / 10;
		i++;
	}
	return (i);
}
