#include "../fdf.h"

void	window(fdf *data)
{
	data->mlx_ptr = mlx_init();
	data->win_x = 1920;
	data->win_y = 1000;
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->win_x, data->win_y, "FDF");
	data->shift_x = 760;
	data->shift_y = 300;
	data->axle.view = 7;
	data->color = 0x24747d;
	data->axle.old_color = 0x7d2424;
	data->zoom = 30;
	data->axle.altitude = 1;
}