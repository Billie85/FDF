#include "fdf.h"
#define  PI 3.14159265358979323846264338327950288

void	isometric(float *x, float *y, int z)
{

	*x = (*x - *y) * cos(0.8);
	printf("x is %f\n", *x);
	*y = (*x + *y) * sin(0.8);
	printf("y is %f\n", *y);
}

 void	search_line(float x0, float y0, float x1, float y1, fdf *data)
{
	float dx, dy, p, x, y;
	int z;
	int z1;

	z = data->z_matrix[(int)y0][(int)x0];
	z1 = data->z_matrix[(int)y1][(int)x1];

//----------zoom----------
	x0 *= data->zoom;
	y0 *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;
//----------color----------
if (z > 0)
{
	data->color = 0xe80c0c;
}
else
{
	data->color = 0xffffff;
}
//----------3D----------
//isometric(&x0, &y0, z);
//isometric(&x1, &y1, z1);

	x = x0;
	while(x <= x1)
	{
		if (x == x0 || x == x1)
		{
			y = y0;
			while(y <= y1)
			{
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
				y++;
			}
		}
			else
			{
				y = y0;
				if (y == y0 || y == y1)
				{
					x = x0;
					while(x <= x1)
					{
						mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, data->color);
						x++;
					}
				}
			}
		x++;
	}

	/* 
//dx = x1-x0;
//dy = y1-y0;

	p = 2 *dy-dx;

	while(x <= x1)
	{
		if(p >= 0)
		{
			printf("aaaaaaaaa");
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xffffff);
			y = y + 1;
			p = p+2*dy-2*dx;
		}
		else
		{
			printf("bbbbbbbbbbb");
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xff0000);
			p = p+2*dy;
		}
		x = x + 1;
	} */
}

void	connect_line(fdf *data)
{
	int x;
	int y;

	 y = 1;
	while(y < data->height)
	{
		x = 1;
		while(x < data->width)
		{
			if (x < data->width -1)
			search_line(x, y, x + 1, y, data);
			if (y < data->height -1)
			search_line(x, y, x, y + 1, data);
			 x++;
		}
		y++;
	}
}