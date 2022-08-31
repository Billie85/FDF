/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 22:18:10 by root              #+#    #+#             */
/*   Updated: 2022/08/29 22:20:48 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dd;
	unsigned char		*ss;

	dd = (unsigned char *)dest;
	ss = (unsigned char *)src;
	if (dd == NULL && ss == NULL)
		return (NULL);
	if (dd < ss)
		ft_memcpy(dest, src, n);
	else
	{
		while (n --)
			*(dd + n) = *(ss + n);
	}
	return (dest);
}
