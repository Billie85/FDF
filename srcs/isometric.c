#include "../fdf.h"

void	isometric(fdf *data)
{
	//-----------------------3D-------------------------------
	data->axle.x = (data->axle.x - data->axle.y) * cos(1.1);
	data->axle.y = (data->axle.x + data->axle.y) * sin(0.5) - data->axle.z / 2;
	data->axle.x1 = (data->axle.x1 - data->axle.y1) * cos(1.1);
	data->axle.y1 = (data->axle.x1 + data->axle.y1) * sin(0.5) - data->axle.z1 / 2;
	//----------------------zoom------------------------------
	data->axle.x *= data->zoom;
	data->axle.x1 *= data->zoom;
	data->axle.y *= data->zoom;
	data->axle.y1 *= data->zoom;
	//----------------------shift---------------------------------------
	data->axle.x += data->shift_x;
	data->axle.y += data->shift_y;
	data->axle.x1 += data->shift_x;
	data->axle.y1 += data->shift_y;
}

/* void	isometric(float *x, float *y, int z)
{
	float angle;
	angle = 0.8;// π／６ isometricの定義
	*x = (*x - *y) * cos(angle);
	*y = (*x + *y) * sin(angle) - z;
} */