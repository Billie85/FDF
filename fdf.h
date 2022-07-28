/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:59:57 by root              #+#    #+#             */
/*   Updated: 2022/07/28 23:25:38 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "get_next_line/get_next_line.h"
#include "mlx_linux/mlx.h"
#include "libft/libft.h"
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

/* **  ------------------------------- resourses --------------------------------
**	--------------- 3D ------------------------------------------
**		x` = (x - y) * cos(angle);
**		y` = (x + y) * sin(angle) - z;
**	-------------------------------------------------------------
** 	------- mlx_function ----------------------------------------
**		void *mlx_ptr;
**		void *win_prt;
**
**		mlx_ptr = mlx_init();
**		win_prt = mlx_new_window(mlx_ptr, 1000, 1000, "FDF");
**
**		mlx_pixel_put(mlx_ptr, win_ptr, (int)x, (int)y, #color);
**
**		mlx_key_hook(win_ptr, deal_key, NULL);
**		mlx_loop(mlx_ptr);
**	--------------------------------------------------------------
**	------- deal_key prototype -----------------------------------
**		int		deal_key(int key, void *data);
**	--------------------------------------------------------------
**	colors:
**		white = 0xffffff
**		red = 0xe80c0c
**	----------------------------
**	frameworks:
**		-framework OpenGL -framework AppKit */

typedef struct 
{
		size_t width;//幅
		size_t height;//高さ
		size_t **z_matrix;//z座標
		int zoom;

		void	*mlx_ptr;
		void	*win_ptr;
}				fdf;

void	read_file(char *file_name, fdf *data);
void	fill_matrix(size_t *z_line, char *line);
void	search_line(int x0, int y0, int x1, int y1, fdf *data);
void	connect_line(fdf *data);

//不思議なことにsize_tのままにしてしまうとlineは出力されないけど、
//intにしてあげると出力される。まじで謎謎
# endif