/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:59:57 by root              #+#    #+#             */
/*   Updated: 2022/08/21 19:33:35 by root             ###   ########.fr       */
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

typedef struct 
{
		int width;//幅
		int height;//高さ
		int **z_matrix;//z座標
		int zoom;
		int color;
		int shift_x;
		int shift_y;

		void	*mlx_ptr;
		void	*win_ptr;
}				fdf;

void	read_file(char *file_name, fdf *data);
void	connect_line(fdf *data);
void    breseham(float x, float y, float x1, float y1, fdf *data);
void	isometric(float *x, float *y, int z);
int		find_max_num(int a, int b);
int		change_sign(int num);

//size_tのままにしてしまうとlineは出力されないけど、
//intにしてあげると出力される。
# endif