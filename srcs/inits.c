/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 22:07:20 by root              #+#    #+#             */
/*   Updated: 2022/08/31 22:07:38 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	inits(t_fdf *data)
{
	data->line = NULL;
	data->i = 0;
	data->map_width = 0;
	data->map_height = 0;
	data->z_matrix = 0;
	data->zoom = 0;
	data->z_matrix_color = 0;
	data->shift_x = 0;
	data->shift_y = 0;
	data->mlx_ptr = 0;
	data->window = 0;
	data->w_x = 0;
	data->w_y = 0;
	data->win_ptr = 0;
	data->file_name = NULL;
	data->map_fd = 0;
	data->w_sum = 0;
}
