/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:54:33 by root              #+#    #+#             */
/*   Updated: 2022/08/31 23:43:55 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	esc_close(t_fdf *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
}

static void	color_key(int key, t_fdf *data)
{
	if (key == 49)
		data->ax.new_color = 0x38006b;
	if (key == 50)
		data->ax.new_color = 0xFF00D0;
	if (key == 51)
		data->ax.new_color = 0xf57f17;
	if (key == 52)
		data->ax.new_color = 0x009999;
	if (key == 53)
		data->ax.new_color = 0x8C00FF;
	if (key == 54)
		data->ax.new_color = 0x700C0B;
	if (key == 55)
		data->ax.new_color = 0xEF6E6E;
	if (key == 56)
		data->ax.new_color = 0xFFA400;
	if (key == 57)
		data->ax.new_color = 0xB9DD64;
	if (key == 58)
		data->ax.new_color = 0xF4D500;
}

static void	zoom_key(int key, t_fdf *data)
{
	if (key == 119)
		data->zoom += 5;
	if (key == 115)
		data->zoom -= 5;
}

static void	z_ax_up_down(int key, t_fdf *data)
{
	if (key == 97)
		data->ax.alt += 0.1;
	if (key == 100)
		data->ax.alt -= 0.1;
}

int	deal_key(int key, t_fdf *data)
{
	if (key == 65362)
		data->shift_y -= 15;
	if (key == 65363)
		data->shift_x += 15;
	if (key == 65364)
		data->shift_y += 15;
	if (key == 65361)
		data->shift_x -= 15;
	if (key == 65307)
		destroy_window(data);
	color_key(key, data);
	zoom_key(key, data);
	z_ax_up_down(key, data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw_wireframe(data);
	return (0);
}
