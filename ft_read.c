/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 22:08:26 by root              #+#    #+#             */
/*   Updated: 2022/07/07 21:12:39 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


size_t split_space(char **split_line)
{
	size_t	len1;

	len1 = 0;
	while (split_line[len1] != NULL)
	{
		printf("%s", split_line[len1]);
		//スペースなしの値が出力される。
		//1234
		//5678
		//9153
		len1++;
	}
	return (len1);
}

void ft_read(char *argv, t_fdf *fdf)
{
	char    *take_out_line;
	char	**split_line;
	int		fd;
	size_t	after_split_space;

	fd = open ("test.txt", R_OK);
	while (take_out_line != NULL)
	{
		take_out_line = get_next_line(fd);
		split_line = ft_split(take_out_line, ' ');
		after_split_space = split_space(split_line);
	}
	free(take_out_line);
	close(fd);
}