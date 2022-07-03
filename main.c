/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:09:04 by root              #+#    #+#             */
/*   Updated: 2022/07/04 00:49:14 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     main(int argc, char **argv)
{
	char    *take_out_line;
	char    **new_map;
	int     i;
	int		fd;

	fd = open("test.txt", O_RDONLY);
	
	take_out_line = get_next_line(fd);
	
	i = 0;
	while(take_out_line[i]  != '\0')
	{
		printf("%s\n", take_out_line);
		take_out_line = get_next_line(fd);
		i++;
	}
}