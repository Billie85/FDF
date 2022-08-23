#include "../fdf.h"

int	get_width(char *file_name)
{
	int	fd;
	char	*get_line;
	char	*take_line;
	char	**split_line;
	int	 width;


	fd = open (file_name, O_RDONLY);
	take_line = get_next_line(fd);
	while (take_line != NULL)
	{
		split_line = ft_split(take_line, ' ');
		width = 0;
		while (split_line[width] != NULL)
			width++;
		free(take_line);
		take_line = get_next_line(fd);
	}
	close(fd);
	return (width); //幅の数は->19
}