#include "fdf.h"

int	close_window(int key, fdf *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	return (0);
}

int mouse_event(int click, fdf *data)
{
	printf("%d\n", click);

	if (click == 1)
		close_window(click, data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	connect_line(data);
	return (0);
}

int	deal_key(int key, fdf *data)
{
	printf("%d\n", key);

	//矢印とw d s aも使えるようにしてる。
	if (key == 119 || key == 65362) //up
		data->shift_y -= 15;
	if (key == 100 || key == 65363) //right
		data->shift_x += 15;
	if (key == 115 || key == 65364) //down
		data->shift_y += 15;
	if (key == 97  || key == 65361) //left
		data->shift_x -= 15;
	if (key == 65307) //esc
		close_window(key, data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	connect_line(data);
	return (0);
}

int     main(int argc, char **argv)
{
	fdf	*data;

	data = (fdf *)malloc(sizeof(fdf));
	read_file(argv[1], data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	data->zoom = 35;
	//breseham(0, 0, 600, 300, data);
	connect_line(data);
	//mlx_hook(data->mlx_win, 33, 1L << 17, close_window, data);
	mlx_key_hook(data->win_ptr, deal_key, data);
	//mlx_mouse_hook(data->win_ptr, mouse_event, data);
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