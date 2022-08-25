#include "../fdf.h"

int destroy_window(fdf *data)
{
	mlx_destroy_window(data->mlx_ptr, data->window);
	exit(0);
	return (0);
}

int		main(int argc, char **argv)
{
	fdf		*data;

	if (argc != 2)
		return (0);
	data = (fdf *)malloc(sizeof(fdf));
	data->file_name = argv[1];
	read_map(data);
	window(data);
	draw_wireframe(data);
	mlx_hook(data->win_ptr, 2, 5, deal_key, data);
	mlx_hook(data->win_ptr, 17, 0, destroy_window, data);
	mlx_loop(data->mlx_ptr);
	close(data->map_fd);
	free(data);
	return (0);
}