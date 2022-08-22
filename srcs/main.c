#include "../fdf.h"

int destroy_window(fdf *data)
{
	mlx_destroy_window(data->mlx_ptr, data->window);
	exit(0);
	return (0);
}

int	deal_key(int key, fdf *data)
{
	if (key == 119 || key == 65362) //up
		data->shift_y -= 15;
	if (key == 100 || key == 65363) //right
		data->shift_x += 15;
	if (key == 115 || key == 65364) //down
		data->shift_y += 15;
	if (key == 97  || key == 65361) //left
		data->shift_x -= 15;
	mlx_clear_window(data->mlx_ptr, data->window);
	connect_line(data);
	return (0);
}

int	main(int argc, char **argv)
{
	fdf	*data;
	
	data = (fdf *)malloc(sizeof(fdf));
	read_file(argv[1], data);
		map_data_init(data);
		connect_line(data);
	mlx_key_hook(data->window, deal_key, data);
	mlx_hook(data->window, 17, 0, destroy_window, data);
	
	//mlx_hook(data->mlx_ptr, 3, 1L << 1, close_window, data);
	//mlx_mouse_hook(data->window, mouse_event, data);
	mlx_loop(data->mlx_ptr);
 /* 	i = 0; //map
	while(i < data->height)
	{
		j = 0;
		while(j < data->width)
		{
			printf("%3ld", data->z_matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	} */
}