NAME		= fdf
PRINTF		= ./ft_printf/libftprintf.a

SRCS		=	./srcs/isometric.c \
				./srcs/draw.c \
				./srcs/fill_matrix.c \
				./srcs/get_width.c \
				./srcs/get_height.c \
				./srcs/ft_read.c \
				./srcs/main.c \
				./srcs/keys.c \
				./srcs/window.c \
				./srcs/color.c \
				./srcs/inits.c \
				./srcs/inits2.c \
				./srcs/draw_wireframe2.c \
				./get_next_line/get_next_line.c \
				./get_next_line/get_next_line_utils.c \

OBJS		= $(SRCS:%.c=%.o)

LIBFT		= ./libft/libft.a

LIBMLX		= libmlx.a

CC			= gcc

CFLAGS		:= -Wall -Wextra -Werror

RM			= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./mlx_linux
	$(MAKE) -C ./libft
	$(MAKE) -C ./ft_printf
	$(CC) $(OBJS) $(LIBFT) $(PRINTF) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	make clean -C ./libft
	make clean -C ./mlx_linux
	make clean -C ./ft_printf
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(LIBFT) $(PRINTF)

re: fclean all

PHONY: fclean clean all re