#include "fdf.h"

 void	search_line(int x0, int y0, int x1, int y1, fdf *data)
{
	int dx, dy, p, x, y;
//----------zoom----------
	x0 *= data->zoom;
	y0 *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;

	dx = x1-x0;
	dy = y1-y0;

	x = x0;

	while(x <= x1)
	{
		if (x == x0 || x == x1)
		{
			y = y0;
			while(y <= y1)
			{
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xffffff);
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
						mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xff0000);
						x++;
					}
				}
			}
		x++;
	}

	/* p = 2 *dy-dx;

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

	 y = 0;
	while(y < data->height)//高さ
	{
		x = 0;
		while(x < data->width)//幅
		{
			search_line(x, y, x + 1, y + 1, data);
			//bresenham_algorithm(x, y, x, y + 2, data);
			 x++;
		}
		y++;
	}
}