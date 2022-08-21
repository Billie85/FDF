NAME		= fdf

SRCS		= ./srcs/map_data_init.c ./srcs/draw.c ./srcs/ft_read.c  ./srcs/main.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c

OBJS		= $(SRCS:%.c=%.o)

LIBFT		= ./libft/libft.a

LIBMLX		= libmlx.a

CC			= gcc

CFLAGS		:= -Wall -Wextra -Werror
#INCS		= -I ./fdf.h ./libft/libft.h

RM			= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./mlx_linux
	$(MAKE) -C ./libft
	$(CC) $(OBJS) $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	make clean -C ./libft
	make clean -C ./mlx_linux
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(LIBFT)

re: fclean all

PHONY: fclean clean all re

#libft and get_next_lineが読み込めなかった部分がいくつかあったけど
#原因としては、srcsの部分で細かく指定されていなかったのが原因
#makefileはget_next_lineにないから、でもlibftの方ではあるから、libftで別で指定しないといけない。