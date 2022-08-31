/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:40:02 by root              #+#    #+#             */
/*   Updated: 2022/08/31 18:48:52 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "mlx_linux/mlx.h"
# include "libft/libft.h"
# include <unistd.h>
# include <stddef.h>
# include <ctype.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <string.h>
# include <stdint.h>
# include <math.h>
# define ESC_KEY 65307

//draw inside the image.
typedef struct s_ax
{
	float	x;
	float	y;
	float	z;
	float	x1;
	float	y1;
	float	z1;
	float	x_f;
	float	y_f;
	float	x1_f;
	float	y1_f;
	float	alt;
	int		color;
	int		new_color;
	int		view;
}			t_ax;

typedef struct s_t_fdf
{
	t_ax	ax;
	char	*line;
	int		i;
	int		map_width;
	int		map_height;
	int		**z_matrix;
	int		zoom;
	int		**z_matrix_color;
	int		shift_x;
	int		shift_y;
	void	*mlx_ptr;
	void	*window;
	int		w_x;
	int		w_y;
	void	*win_ptr;
	char	*file_name;
	int		map_fd;
	int		w_sum;
}				t_fdf;

int		**malloc_z_matrix(int map_width, int map_height);
void	fill_matrix(int *z_line, char *line);
int		get_width(t_fdf *data);
int		get_height(t_fdf *data);
void	read_map(t_fdf *data);
void	draw_wireframe(t_fdf *data);
void	breseham(t_fdf *data);
void	isometric(t_fdf *data);
void	init_struct(t_fdf *data);
int		deal_key(int key, t_fdf *data);
int		key2(int key, t_fdf *data);
void	window(t_fdf *data);
int		destroy_window(t_fdf *data);
void	color(t_fdf *data);
void	width_x(t_fdf *data);
void	height_y(t_fdf *data);
#endif
