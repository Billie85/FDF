/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 22:07:24 by root              #+#    #+#             */
/*   Updated: 2022/08/31 22:07:33 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	inits2(t_ax *data)
{
	data->x = 0;
	data->y = 0;
	data->z = 0;
	data->x1 = 0;
	data->y1 = 0;
	data->z1 = 0;
	data->x_f = 0;
	data->y_f = 0;
	data->x1_f = 0;
	data->y1_f = 0;
	data->alt = 0;
	data->color = 0;
	data->new_color = 0;
	data->view = 0;
}
