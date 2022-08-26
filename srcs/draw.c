#include "../fdf.h"

void		info(fdf *data)
{
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 10, 0x247d58,
	"To change scale use + or - ");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 30, 0x247d58,
	"To change altitude use Q or W");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 50, 0x247d58,
	"To move use arrow buttons");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 70, 0x247d58,
	"To change colors use R G B or C");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, 90, 0x247d58,
	"To change type of projection use Z or X");
}

void	color(fdf *data)
{
	data->axle.color = ( data->axle.z != 0 ||  data->axle.z1 != 0) ? data->axle.old_color +  data->axle.z * 2 : 0xffffff;
}


static float	find_max_num(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

static float	change_sign(float num){
   if (num > 0)
      return num;
   else
      return -num;
}

void	init_xyz(fdf *data)
{
	data->axle.z = data->z_matrix[(int)data->axle.y_f][(int)data->axle.x_f] * data->axle.altitude;
	data->axle.z1 = data->z_matrix[(int)data->axle.y1_f][(int)data->axle.x1_f] * data->axle.altitude;
	data->axle.x = data->axle.x_f;
	data->axle.x1 = data->axle.x1_f;
	data->axle.y = data->axle.y_f;
	data->axle.y1 = data->axle.y1_f;
}

void    breseham(fdf *data)
{
	float x_step;
	float y_step;
	float max;

	init_xyz(data);
	color(data);
	if(data->axle.view == 7)
	 	isometric(data);
		else
		flat_part(data);
	x_step = data->axle.x1 - data->axle.x;
	y_step = data->axle.y1 - data->axle.y;
	max = find_max_num(change_sign(x_step), change_sign(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(data->axle.x - data->axle.x1) || (int)(data->axle.y - data->axle.y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, data->axle.x, data->axle.y, data->axle.color);
		data->axle.x += x_step;
		data->axle.y += y_step;
	}
}

void	draw_wireframe(fdf *data)
{
	//info(data);
	 data->axle.y_f = 0;

	while (data->axle.y_f < data->map_height)
	{
		data->axle.x_f = 0;
		while(data->axle.x_f < data->map_width)
		{
			if (data->axle.x_f < data->map_width -1)
			{
				data->axle.x1_f = data->axle.x_f + 1;
				data->axle.y1_f = data->axle.y_f;
				breseham(data);
			}
			if (data->axle.y_f < data->map_height -1)
			{
				data->axle.x1_f = data->axle.x_f;
				data->axle.y1_f = data->axle.y_f + 1;
				breseham(data);
			}
			data->axle.x_f++;
		}
		data->axle.y_f++;
	}
}