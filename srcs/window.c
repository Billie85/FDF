/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 09:42:12 by root              #+#    #+#             */
/*   Updated: 2022/08/27 22:43:10 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	window(t_fdf *data)
{
	data->mlx_ptr = mlx_init();
	data->w_x = 1920;
	data->w_y = 1000;
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->w_x, data->w_y, "FDF");
	data->shift_x = 760;
	data->shift_y = 300;
	data->ax.view = 7;
	data->ax.color = 0x24747d;
	data->zoom = 30;
	data->ax.alt = 1;
}
