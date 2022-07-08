/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:09:04 by root              #+#    #+#             */
/*   Updated: 2022/07/08 23:52:55 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     main(int argc, char **argv)
{
	fdf	*data;
	size_t i;
	size_t j;

	data = (fdf *)malloc(sizeof(fdf));
	read_file(argv[1], data);
	
/* 	i = 0;
	while(i < data->height)
	{
		j = 0;
		while(j < data->width)
		{
			//printf("%3d", data->z_matrix[i][j]);
			j++;
		}
		printf("\n");
		i++;
	} */
}