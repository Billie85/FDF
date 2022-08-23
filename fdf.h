#ifndef FDF_H
# define FDF_H
# define ANGLE         0.52359877
# define X_VER 0
 # define Y_VER 1

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

//draw inside the image.
typedef struct s_axle
{
	float	x;
	float	x1;
	float	y;
	float	y1;
	float	z;
	float	z1;
	int		color;
}			t_axle;

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
		void	*window;
		int		win_x;
		int		win_y;
		void	*win_ptr;
		char	*map_path;
}				fdf;

void	fill_matrix(int *z_line, char *line);
int		get_width(char *file_name);
int		get_height(char *file_name);
void	read_map(fdf **data);
void	draw_wireframe(fdf **data);
void    breseham(t_axle *inside, fdf *data);
void	isometric(float *x, float *y, float *z);
void	init_struct(fdf *data);

//size_tのままにしてしまうとlineは出力されないけど、
//intにしてあげると出力される。
# endif