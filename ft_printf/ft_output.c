/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayumi <kayumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 12:43:42 by kayumi            #+#    #+#             */
/*   Updated: 2022/01/02 19:23:42 by kayumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_output(char **max)
{
	char	*tmp;

	tmp = *max;
	while (**max != '\0' && **max != '%')
	{
		(*max)++;
	}
	return (write(1, tmp, *max - tmp));
}
