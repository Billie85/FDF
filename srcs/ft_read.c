/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 11:35:23 by root              #+#    #+#             */
/*   Updated: 2022/08/27 21:18:35 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	read_map(t_fdf *r)
{
	r->map_height = get_height(r);
	r->map_width = get_width(r);
	r->z_matrix = (int **)malloc(sizeof(int *) * (r->map_height + 1));
	r->i = 0;
	while (r->i <= r->map_height)
		r->z_matrix[r->i++] = (int *)malloc(sizeof(int) * (r->map_width + 1));
	r->i = 0;
	r->map_fd = open(r->file_name, O_RDONLY, 0);
	if (r->map_fd == -1)
	{
		ft_printf("Could not open file.\n");
		exit (EXIT_FAILURE);
	}
	r->line = get_next_line(r->map_fd);
	while (r->line != NULL)
	{
		fill_matrix(r->z_matrix[r->i++], r->line);
		r->line = get_next_line(r->map_fd);
	}
	close(r->map_fd);
}
