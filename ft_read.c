/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 22:08:26 by root              #+#    #+#             */
/*   Updated: 2022/07/07 23:10:45 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//get height->最初にマップの高さを調べるよ。
size_t	get_height(char *file_name)
{
	int fd;
	size_t height;
	
	fd = open (file_name, O_RDONLY);
	
	height = 0;
	while(get_next_line(fd) != NULL)
	{
		height++;
		//printf("%ld\n", height); //10
	}
	close(fd);
	return (height);
}

//マップの中にあるスペース達を飛ばしていく。
size_t split_space(char **split_line)
{
	size_t	len1;

	len1 = 0;
	while (split_line[len1] != NULL)
	{
		//printf("%s", split_line[len1]); //mapが出力される。
		//スペースなしの値が出力される。
		//1234
		//5678
		//9153
		len1++;
	}
	return (len1);
}

//get_width-> 幅を調べていくよ
size_t	get_width(char *file_name)
{
	int	fd;
	char *get_line;
	size_t width;
	char    *take_line;
	char	**split_line;
	
	fd = open (file_name, O_RDONLY);
	while (take_line != NULL)
	{
		take_line = get_next_line(fd);
		split_line = ft_split(take_line, ' ');
		width = split_space(split_line);
	}
	free(take_line);
	close(fd);
	return (width); //幅の数は->19
}



//file_nameの中にはmainの方で最初に読み込んだファイルが入ってるよ。
void	read_file(char *file_name, fdf *data)
{
	//1, get the height;
	//2, get the width
	int fd;
	char *line;
	
	data->height = get_height(file_name);//高さ
	data->width = get_width(file_name);//幅

	data->z_matrix = (int *)malloc(sizeof(int *) * (data->height + 1))//z軸
	
}