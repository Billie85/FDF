#include "fdf.h"
//#define MAX(a, b) (a > b ? a : b);

//傾きを求めたい ->直線上の2点を任意に取り、それらを (x, y), (x1, y1) m に代入する。
/* float	gradient(float X, float Y)
{
	float	m;
	
	if((X) == 0)
		m = (Y);
	else
	m = (Y) / (X);
	return (m);
}

void	bresenham_algorithm(float x, float y, float x1, float y1, fdf *data)
{
	float	max;
	float	X = x1 - x; //開始座標
	float	Y = y1 - y;//終了座標
	float	P;

	max = gradient(X, Y);//傾き
	X /= max;
	Y /= max;
	P = 2 *Y - X;
	 while((size_t)(x - x1) || (size_t)(y - y1))
	{
		if(P >= 0)
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xffffff);
			y += Y;
			P = P+2*Y-2*X;
		}
		else
		{
			mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xffffff);
			P = P+2*Y;
			x += X;
		}
	}
} */

void	bresenham_algorithm(int x0, int y0, int x1, int y1, fdf *data)
{
	int dx, dy, p, x, y;
	dx = x1-x0;
	x = x0;
	y = y0;
	p =2 *dy-dx;

	while(x <= x1)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xffffff);
		x++;
		if(p >= 0)
		{
			p = p+2*dy-2*dx;
		}
		else
		{
			p =p+2*dy;
			y++;
		}
	}
}