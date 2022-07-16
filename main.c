 #include "fdf.h"

int	deal_key(int key, void *data)
{
	printf("%d", key);
	return (0);
}

int     main(int argc, char **argv)
{
	fdf	*data;
	size_t i;
	size_t j;

	data = (fdf *)malloc(sizeof(fdf));
	read_file("color.txt", data);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");

	bresenham_algorithm(10, 10, 600, 300, data);
	mlx_key_hook(data->win_ptr, deal_key, NULL);
	mlx_loop(data->mlx_ptr);
	
 	i = 0; //map
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
	}
}