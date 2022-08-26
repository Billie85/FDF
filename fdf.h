#ifndef FDF_H
# define FDF_H
# define ANGLE         0.52359877
# define ANSI_COLOR_ORANGE ft_printf("\x1b[33m");
# define BACK_COLOR	ft_printf("\x1b[0m");

#include "ft_printf/ft_printf.h"
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
	float	y;
	float	z;
	float	x1;
	float	y1;
	float	z1;
	float	x_f;
	float	y_f;
	float	x1_f;
	float	y1_f;
	float	altitude;
	int		color;
	int		old_color;
	int		view;
}			t_axle;


typedef struct 
{
		t_axle axle;
		char *line;
		int		i;
		int 	map_width;//幅
		int 	map_height;//高さ
		int 	**z_matrix;//z座標
		int 	zoom;
		int 	color;
		int		**z_matrix_color;
		int 	shift_x;
		int 	shift_y;
		void	*mlx_ptr;
		void	*window;
		int		win_x;
		int		win_y;
		void	*win_ptr;
		char	*file_name;
		int		map_fd;
		int		w_sum;
}				fdf;

int **malloc_z_matrix(int map_width, int map_height);
void	fill_matrix(int *z_line, char *line);
int		get_width(fdf *data);
int		get_height(fdf *data);
void	read_map(fdf *data);
void	draw_wireframe(fdf *data);
void    breseham(fdf *data);
void	isometric(fdf *data);
void	init_struct(fdf *data);
void	flat_part(fdf *data);
int		deal_key(int key, fdf *data);
int		key2(int key, fdf *data);
void	window(fdf *data);


//size_tのままにしてしまうとlineは出力されないけど、
//intにしてあげると出力される。
# endif