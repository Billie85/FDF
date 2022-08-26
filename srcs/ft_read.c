#include "../fdf.h"

void	read_map(fdf *data)
{
	data->map_height = get_height(data);//高さ //11
	data->map_width =  get_width(data);//幅 //19

	data->z_matrix = (int **)malloc(sizeof(int*) * (data->map_height + 1)); //z軸

	data->i = 0;
	while (data->i <= data->map_height)
		data->z_matrix[data->i++] = (int *)malloc(sizeof(int) * (data->map_width + 1));

	data->i = 0;
	data->map_fd = open(data->file_name, O_RDONLY, 0);
	data->line = get_next_line(data->map_fd);
	while (data->line != NULL)
	{
		fill_matrix(data->z_matrix[data->i++], data->line);
		data->line = get_next_line(data->map_fd);
	}
	close(data->map_fd);
}
//intの形で高さの情報を収納する行列を作って
//高さの数字を書き込んでいく