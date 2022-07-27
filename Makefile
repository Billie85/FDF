NAME		= fdf

SRCS		= main.c ft_read.c draw.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c

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
#$(CC) $(FLAGS) -L $(LIBFT) -L $(MLX) -o $@ $^ -lft -lmlx -lXext -lX11 -lm
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