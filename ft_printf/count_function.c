/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayumi <kayumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:31:32 by kayumi            #+#    #+#             */
/*   Updated: 2021/12/10 13:31:33 by kayumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	count_function(int number)
{
	size_t	i;

	i = 0;
	while (number != 0)
	{
		number = number / 16;
		i++;
	}
	return (i);
}
