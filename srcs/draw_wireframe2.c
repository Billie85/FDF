/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wireframe2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 00:35:49 by root              #+#    #+#             */
/*   Updated: 2022/09/01 00:39:48 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	width_x(t_fdf *data)
{
	if (data->ax.x_f < data->map_width - 1)
	{
		data->ax.x1_f = data->ax.x_f + 1;
		data->ax.y1_f = data->ax.y_f;
		breseham(data);
	}
}

void	height_y(t_fdf *data)
{
	if (data->ax.y_f < data->map_height - 1)
	{
		data->ax.x1_f = data->ax.x_f;
		data->ax.y1_f = data->ax.y_f + 1;
		breseham(data);
	}
}
