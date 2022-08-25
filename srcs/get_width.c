#include "../fdf.h"

int	get_width(fdf *data)
{
	char	*take_line;
	char	**split_line;
	
	data->map_width = 0;

	data->map_fd = open(data->file_name, O_RDONLY);
	take_line = get_next_line(data->map_fd);
	while (take_line != NULL)
	{
		split_line = ft_split(take_line, ' ');

		while (split_line[data->map_width] != NULL)
			data->map_width++;
			free(take_line);
		take_line = get_next_line(data->map_fd);
	}
	close(data->map_fd);
	return (data->map_width); //幅の数は->19
}