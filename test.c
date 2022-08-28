# include "libft/libft.h"
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
# include "mlx_linux/mlx.h"


int	destroy_window(t_fdf *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	exit(0);
	return (0);
}

int	esc_window(int key, t_fdf *data)
{
	printf("hi\n");
	if (key == 65307)
		destroy_window (data);
}

int	main(int argc, char **argv)
{
	t_fdf		*data;

	data = (t_fdf *)malloc(sizeof(t_fdf));
	data->mlx_ptr = mlx_init();
	data->w_x = 1920;
	data->w_y = 1000;
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->w_x, data->w_y, "FDF");
	mlx_hook(data->win_ptr, 2, 1L << 0, esc_window, data);
	mlx_loop(data->mlx_ptr);
	close(data->map_fd);
	free(data);
	return (0);
}
