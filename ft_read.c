/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 22:08:26 by root              #+#    #+#             */
/*   Updated: 2022/07/06 11:04:53 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_read(char *argv, t_fdf *fdf)
{
	char    *take_out_line;
	char	**split_line;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	
	//take_out_line = malloc(sizeof(char) * fd);
	take_out_line = get_next_line(fd);
	
	while(take_out_line  != '\0')
	{
		//printf("%s\n", take_out_line);
		//take_out_line = get_next_line(fd);
		free(take_out_line);
		take_out_line = get_next_line(fd);
		//split_line = ft_split(take_out_line, ' ');
		//printf("%s\n", *split_line);
	}
	free(take_out_line);
	close(fd);
}