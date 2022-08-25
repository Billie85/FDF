#include "../fdf.h"

static void color_key(int key, fdf *data)
{
	if (key == 49)
		data->axle.old_color = 0x33ff00; //green
	if (key == 50)
		data->axle.old_color = 0xFF00D0; //pink
	if (key == 51)
		data->axle.old_color = 0x664200; //orange
	if (key == 52)
		data->axle.old_color = 0x009999; //blue
	if (key == 53)
		data->axle.old_color = 0x8C00FF; //purple
	if (key == 54)
		data->axle.old_color = 0x700C0B;
	if (key == 55)
		data->axle.old_color = 0xEF6E6E;
	if (key == 56)
		data->axle.old_color = 0xFFA400;
	if (key == 57)
		data->axle.old_color = 0xB9DD64;
	if (key == 58)
		data->axle.old_color = 0xF4D500;
}

static void view_key(int key, fdf *data)
{
		if (key == 122)//z
		data->axle.view = 6;
	if (key == 120)//x
		data->axle.view = 7;
}
static void zoom_key(int key, fdf *data)
{
	if (key == 119)//w
		data->zoom  += 5;
	if (key == 115)//s
		data->zoom -= 5;
}
static void z_axle_up_down(int key, fdf *data)
{
	if (key == 97)
	data->axle.altitude += 0.1;//a
	if (key == 100)
		data->axle.altitude -= 0.1;//d
}

int	deal_key(int key, fdf *data)
{
	if (key == 65362) //up
		data->shift_y -= 15;
	if (key == 65363) //right
		data->shift_x += 15;
	if (key == 65364) //down
		data->shift_y += 15;
	if (key == 65361) //left
		data->shift_x -= 15;
	color_key(key, data);
	view_key(key, data);
	zoom_key(key, data);
	z_axle_up_down(key, data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw_wireframe(data);
	return (0);
}