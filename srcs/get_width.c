/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:37:08 by root              #+#    #+#             */
/*   Updated: 2022/08/31 16:27:06 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	get_width(t_fdf *data)
{
	char	*take_line;
	char	**split_line;
	int		i;

	data->map_width = 0;
	data->map_fd = open(data->file_name, O_RDONLY);
	take_line = get_next_line(data->map_fd);
	while (take_line != NULL)
	{
		split_line = ft_split(take_line, ' ');
		while (split_line[data->map_width] != NULL)
			data->map_width++;
		free(take_line);
		i = 0;
		while (split_line[i] != NULL)
		{
			free(split_line[i]);
			i++;
		}
		free(split_line);
		take_line = get_next_line(data->map_fd);
	}
	close(data->map_fd);
	return (data->map_width);
}
