/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 11:35:23 by root              #+#    #+#             */
/*   Updated: 2022/08/31 23:07:38 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	print_error(void)
{
	ft_printf("Could not open file.\n");
	exit (EXIT_FAILURE);
}

void	free_function(t_fdf *data)
{
	free(data->z_matrix);
	data->z_matrix = NULL;
}

void	read_map(t_fdf *r)
{
	int	i;

	r->map_height = get_height(r);
	r->map_width = get_width(r);
	r->z_matrix = (int **)malloc(sizeof(int *) * (r->map_height + 1));
	if (r->z_matrix == NULL)
		free_function(r);
	r->i = 0;
	while (r->i <= r->map_height)
		r->z_matrix[r->i++] = (int *)malloc(sizeof(int) * (r->map_width + 1));
	if (r->z_matrix == NULL)
		free_function(r);
	r->i = 0;
	r->map_fd = open(r->file_name, O_RDONLY, 0);
	if (r->map_fd == -1)
		print_error ();
	while (1)
	{
		r->line = get_next_line(r->map_fd);
		if (r->line == NULL)
			break ;
		fill_matrix(r->z_matrix[r->i++], r->line);
		free(r->line);
	}
}
