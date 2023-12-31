NAME = cub3d

SRCS = SRCS/*.c\
	   SRCS/parsing/*.c\
	   SRCS/exit/*.c\
	   SRCS/game/*.c


OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS_MLX = -lXext -lX11 -lm -o
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

MLX_PATH  = includes/minilibx-linux/
MLX_COMPILE = make -C $(MLX_PATH)
MLX_EXEC = libmlx.a
MLX = $(MLX_PATH)$(MLX_EXEC)

all:			$(NAME)

$(NAME):		$(OBJS)
				$(MLX_COMPILE)
				$(CC) $(SRCS) $(MLX) $(CFLAGS_MLX) $(NAME) -g -O3
				
clean:
			$(RM) $(OBJS)
			
fclean:		clean
			$(RM) $(NAME)
			
re:			fclean all

.PHONY:		all clean fclean re
