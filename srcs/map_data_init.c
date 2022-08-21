#include "../fdf.h"

void	map_data_init(fdf *data)
{
	data->window = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	data->zoom = 35;
}