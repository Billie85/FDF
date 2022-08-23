#include "../fdf.h"

void	isometric(fdf *data, double angel)
{
	data->x = (data->x - data->y) * cos(angel);
	data->y = (data->x + data->y) * sin(angel) - data->z;
}