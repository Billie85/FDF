/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 22:08:26 by root              #+#    #+#             */
/*   Updated: 2022/07/07 20:07:14 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_read(char *argv, t_fdf *fdf)
{
	char    *take_out_line;
	char	**split_line;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	take_out_line = get_next_line(fd);
	
	int i = 0;
	while(take_out_line != NULL)
	{
		split_line = ft_split(take_out_line, ' ');
		printf("%s\n", split_line[i]);
		//take_out_line = get_next_line(fd);
		i++;
	}
	free(take_out_line);
	close(fd);
}