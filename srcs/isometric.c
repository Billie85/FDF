/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:33:38 by root              #+#    #+#             */
/*   Updated: 2022/08/27 18:47:15 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	zoom_part(t_fdf *data)
{
	data->ax.x *= data->zoom;
	data->ax.x1 *= data->zoom;
	data->ax.y *= data->zoom;
	data->ax.y1 *= data->zoom;
}

static void	shift_part(t_fdf *data)
{
	data->ax.x += data->shift_x;
	data->ax.y += data->shift_y;
	data->ax.x1 += data->shift_x;
	data->ax.y1 += data->shift_y;
}

void	isometric(t_fdf *data)
{
	data->ax.x = (data->ax.x - data->ax.y) * cos(1.1);
	data->ax.y = (data->ax.x + data->ax.y) * sin(0.5) - data->ax.z / 8;
	data->ax.x1 = (data->ax.x1 - data->ax.y1) * cos(1.1);
	data->ax.y1 = (data->ax.x1 + data->ax.y1) * sin(0.5) - data->ax.z1 / 8;
	zoom_part(data);
	shift_part(data);
}
