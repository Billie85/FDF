#include "../fdf.h"

/* void	isometric(float *x, float *y, int z)
{
	float angle;
	angle = 0.8;// π／６ isometricの定義
	*x = (*x - *y) * cos(angle);
	*y = (*x + *y) * sin(angle) - z;
} */

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

void    breseham(t_axle *map_inside, fdf *data)
{
	printf("aaaaaaaaaaa\n");

	float x_step;
	float y_step;
	float max;

	map_inside->z = (float)data->z_matrix[(int)map_inside->y][(int)map_inside->x];
	map_inside->z1 = (float)data->z_matrix[(int)map_inside->y1][(int)map_inside->x1];

	//----------zoom----------
	map_inside->x *= data->zoom;
	map_inside->y *= data->zoom;
	map_inside->x1 *= data->zoom;
	map_inside->y1 *= data->zoom;
	//----------color----------
	//ここにマップからの色を取ってくる！
	//----------3D----------
	isometric(&map_inside->x, &map_inside->y, &map_inside->z);
	isometric(&map_inside->x1, &map_inside->y1, &map_inside->z1);
	//----------shift----------
	map_inside->x += data->shift_x;
	map_inside->y += data->shift_y;
	map_inside->x1 += data->shift_x;
	map_inside->y1 += data->shift_y;

	x_step = map_inside->x1 - map_inside->x;
	y_step = map_inside->y1 - map_inside->y;
	max = find_max_num(change_sign(x_step), change_sign(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(map_inside->x - map_inside->x1) || (int)(map_inside->y - map_inside->y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, map_inside->x, map_inside->y, map_inside->color);
		map_inside->x += x_step;
		map_inside->y += y_step;
	}
}

static void check_x_y(int x, int y, t_axle *map_inside, fdf *data, int check)
{
	if (check == X_VER)
	{
		map_inside->x = x;
		map_inside->x1 = x + 1;
		map_inside->y = y;
		map_inside->y1 = y;
	}
	if (check == Y_VER)
	{
		map_inside->x = x;
		map_inside->x1 = x;
		map_inside->y = y;
		map_inside->y1 = y + 1;
	}
}

void	draw_wireframe(fdf **data)
{
	printf("in the function draw_wireframe\n");
	int x;
	int y;
	t_axle *map_inside;//ここで新しい構造体入る！
	map_inside = (t_axle *) malloc(sizeof(t_axle));
	map_inside->z = 0;
	map_inside->z1 = 0;
	
	 y = 0;
	while(y < (*data)->height)
	{
		printf("----in while draw_wireframe----\n");
		x = 0;
		while(x < (*data)->width)
		{
			if (x < (*data)->width -1)
			{
				check_x_y(x, y, map_inside, *data, X_VER);
				breseham(map_inside, (*data));
			}
			if (y < (*data)->height -1)
			{
				check_x_y(x, y, map_inside, *data, Y_VER);
				breseham(map_inside, (*data));
			}
			x++;
		}
		y++;
	}
}