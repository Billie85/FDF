#include "../fdf.h"

void		flat_part(fdf *data)
{
	//3d-----------------------------
	data->axle.x /= cos(1.1);
	data->axle.y /= sin(0.5);
	data->axle.x1 /= cos(1.1);
	data->axle.y1 /= sin(0.5);
	//zoom--------------------------
	data->axle.x *= data->zoom / 4;
	data->axle.x1 *= data->zoom / 4;
	data->axle.y *= data->zoom / 4;
	data->axle.y1 *= data->zoom / 4;
	//shift----------------------------
	data->axle.x += data->shift_x;
	data->axle.y += data->shift_y;
	data->axle.x1 += data->shift_x;
	data->axle.y1 += data->shift_y;
}