/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_height.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:36:49 by root              #+#    #+#             */
/*   Updated: 2022/08/31 19:51:04 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	get_height(t_fdf *data)
{	char *tmp;

	data->map_height = 0;
	data->map_fd = open (data->file_name, O_RDONLY, 0);
	
	while (1)
	{
		tmp =  get_next_line(data->map_fd);
		if (tmp == NULL)
			break ;
		data->map_height++;
		free(tmp);
	}
	close(data->map_fd);
	return (data->map_height);
}
