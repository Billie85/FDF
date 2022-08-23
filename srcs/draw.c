#include "../fdf.h"

void	isometric(float *x, float *y, int z)
{
	float angle;
	angle = 0.8;// π／６ isometricの定義
	*x = (*x - *y) * cos(angle);
	*y = (*x + *y) * sin(angle) - z;
}

int	find_max_num(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	change_sign(int num){
   if (num > 0)
      return num;
   else
      return -num;
}

void    breseham(float x, float y, float x1, float y1, fdf *data)
{
	float z;
	float z1;
	float x_step;
	float y_step;
	int max;
	int color;

	z = data->z_matrix[(int)y][(int)x];
	z1 = data->z_matrix[(int)y1][(int)x1];

	//----------zoom----------
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
	//----------color----------
	//ここの部分は直さないといけない。
	//マスを多く一個とちゃってる
/* if (z > 0 || z1 > 0)
	data->color = 0xA64D79;
else
	data->color = 0xffffff; */
	//data->color = (z || z1) ? 0xe80c0c : 0xffffff;

	//----------3D----------
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);
	//----------shift----------
	x += data->shift_x;
	y += data->shift_y;
	x1 += data->shift_x;
	y1 += data->shift_y;

	x_step = x1 - x;
	y_step = y1 - y;
	max = find_max_num(change_sign(x_step), change_sign(y_step));
	x_step /= max;
	y_step /= max;

	//color = (z || z1) ? 0xfc0345 : 0xBBFAFF;
	//color = (z != z1) ? 0xfc031c : color;

/* 	if (z > 0 || z1 > 0)
		color = 0xffffff;
	else
		color = 0xfc0345; */
		
	if (z > 0 != z1 > 0)
		color = 0xfc0345;//平らな部分の支えとなる柱みたいな（高さ）
	else
		color = 0xBBFAFF;//平らな部分

	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, color);
		x += x_step;
		y += y_step;
		if (x > data->win_x || y > data->win_y || y < 0 || x < 0)
			break ;
	}
}

void	draw_map(fdf *data)
{
	int x;
	int y;

	 y = 0;
	while(y < data->height)
	{
		x = 0;
		while(x < data->width)
		{
			if (x < data->width -1)
				breseham(x, y, x + 1, y, data);
			if (y < data->height -1)
				breseham(x, y, x, y + 1, data);
			 x++;
		}
		y++;
	}
}