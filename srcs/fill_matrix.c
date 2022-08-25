#include "../fdf.h"

void	fill_matrix(int *z_line, char *line)
{
	int 	i;
	char	**split_line;

	i = 0;
	split_line = ft_split(line, ' ');
	while(split_line[i] != NULL)
	{
		z_line[i] = ft_atoi(split_line[i]);
		free(split_line[i]);
		i++;
	}
	free(split_line[i]);
}