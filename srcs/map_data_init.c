#include "../fdf.h"

void	map_data_init(fdf *data)
{
	data->zoom = 35;
	data->win_x = 2000;
	data->win_y = 1000;
	data->mlx_ptr = mlx_init();
	data->win_ptr = \
	data->window = mlx_new_window(data->mlx_ptr, data->win_x, data->win_y, "FDF");
}