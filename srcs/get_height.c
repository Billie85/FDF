/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_height.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:36:49 by root              #+#    #+#             */
/*   Updated: 2022/08/27 18:47:08 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	get_height(t_fdf *data)
{	
	data->map_height = 0;
	data->map_fd = open (data->file_name, O_RDONLY, 0);
	while (get_next_line(data->map_fd) != NULL)
		data->map_height++;
	close(data->map_fd);
	return (data->map_height);
}
