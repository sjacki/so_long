NAME = so_long

SRCS =	check_map.c	check_things.c	check_walls.c \
		draw_map.c	get_next_line.c	\
		movements.c	read_file.c	\
		so_long.c	utils.c	utils2.c \

INCLUDE = include/so_long.h

OBJS = $(SRCS:.c=.o)

CC = gcc 

CFLAGS = -Wall -Wextra -Werror

MLX = -framework OpenGL -framework AppKit -lmlx

all : $(NAME)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@  

$(NAME) : $(OBJS) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJS) -I./include $(MLX) libmlx.dylib -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

bonus : $(NAME)

.PHONY: clean fclean re all