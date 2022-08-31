/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kayumi <kayumi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:31:11 by kayumi            #+#    #+#             */
/*   Updated: 2022/01/02 19:47:50 by kayumi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

size_t	ft_putstr(char *n)
{
	if (n == NULL)
		return (write(1, "(null)", 6));
	return (write(1, n, ft_strlen(n)));
}
