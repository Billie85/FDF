#include "../fdf.h"


void	isometric(float *x, float *y, float *z)
{
	*x = (*x - *y) * cos(ANGLE);
	*y = (*x + *y) * sin(ANGLE) - *z;
}

/* void	isometric(float *x, float *y, int z)
{
	float angle;
	angle = 0.8;// π／６ isometricの定義
	*x = (*x - *y) * cos(angle);
	*y = (*x + *y) * sin(angle) - z;
} */