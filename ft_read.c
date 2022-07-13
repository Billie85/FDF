#include "fdf.h"

//get height->最初にマップの高さを調べるよ。
size_t	get_height(char *file_name)//OK
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

//get_width-> 幅を調べていくよ
size_t	get_width(char *file_name)
{
	int	fd;
	char	*get_line;
	char	*take_line;
	char**split_line;
	size_t	 width;


	fd = open (file_name, O_RDONLY);
	take_line = get_next_line(fd);
	while (take_line != NULL)
	{
		split_line = ft_split(take_line, ' ');
		width = 0;
		while (split_line[width] != NULL)
			//printf("%s", split_line[width]);
			width++;
		free(take_line);
		take_line = get_next_line(fd);
	}
	close(fd);
	return (width); //幅の数は->19
}

void	fill_matrix(size_t *z_line, char *line)
{
	size_t 	i;
	char	**split_line;

	split_line = ft_split(line, ' ');
	i = 0;
	while(split_line[i] != NULL)
	{
		z_line[i] = ft_atoi(split_line[i]);
		free(split_line[i]);
		i++;
	}
	free(split_line[i]);
}

//file_nameの中にはmainの方で最初に読み込んだファイルが入ってるよ。
void	read_file(char *file_name, fdf *data)
{
	//1, get the height;
	//2, get the width
	int fd;
	char *line;
	size_t	i;
	
	data->height = get_height(file_name);//高さ
	data->width = get_width(file_name);//幅

	data->z_matrix = (size_t **)malloc(sizeof(size_t*) * (data->height + 1)); //z軸
	i = 0;
	while(i <= data->height) //高さの数は10だから10回る。
	{
			data->z_matrix[i] = (size_t*)malloc(sizeof(size_t) * (data->width + 1));
			i++;
	}
		fd = open (file_name, O_RDONLY);
		line = get_next_line(fd);
		i = 0;
		while (line != NULL)
		{
			fill_matrix(data->z_matrix[i], line);
			free(line);
			line = get_next_line(fd);
			i++;
		}
		close(fd);
		data->z_matrix[i] = NULL;
//intの形で高さの情報を収納する行列を作って
//高さの数字を書き込んでいく
//

}