#include "../fdf.h"

int	get_height(fdf *data)
{	
	data->map_height = 0;
	data->map_fd = open (data->file_name, O_RDONLY, 0);
	
	while(get_next_line(data->map_fd) != NULL)
		data->map_height++;
	close(data->map_fd);
	//printf("data->map_height is %d\n", data->map_height);//11
	return(data->map_height);
}