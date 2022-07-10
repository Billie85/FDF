#include "fdf.h"

int     main(int argc, char **argv)
{
	fdf	*data;
	size_t i;
	size_t j;

	data = (fdf *)malloc(sizeof(fdf));
	read_file("color.txt", data);
	
/* 	i = 0;
	while(i < data->height)
	{
		j = 0;
		while(j < data->width)
		{
			//printf("%3d", data->z_matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	} */
}