#include "../fdf.h"

int	get_height(char *file_name)//OK
{
	int fd;
	int height;
	
	fd = open (file_name, O_RDONLY);
	
	height = 0;
	while(get_next_line(fd) != NULL)
		height++;
	close(fd);
	return (height);
}