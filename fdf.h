/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:59:57 by root              #+#    #+#             */
/*   Updated: 2022/07/30 01:40:41 by root             ###   ########.fr       */
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
		int width;//幅
		int height;//高さ
		int **z_matrix;//z座標
		int zoom;
		int color;

		void	*mlx_ptr;
		void	*win_ptr;
}				fdf;

void	read_file(char *file_name, fdf *data);
//void	search_line(float x0, float y0, float x1, float y1, fdf *data);
void	connect_line(fdf *data);
void    breseham(float x, float y, float x1, float y1, fdf *data);

//不思議なことにsize_tのままにしてしまうとlineは出力されないけど、
//intにしてあげると出力される。まじで謎謎
# endif