NAME = so_long

SRCS =	srcs/check_map.c	srcs/check_things.c	srcs/check_walls.c \
		srcs/draw_map.c	srcs/get_next_line.c	\
		srcs/movements.c	srcs/ft_get_map.c	\
		srcs/so_long.c	srcs/utils.c	srcs/utils2.c \
		srcs/get_next_line_utils.c srcs/ft_split.c srcs/ft_substr.c srcs/ft_itoa.c

INCLUDE = headers/so_long.h

OBJS = $(SRCS:.c=.o)

CC = gcc 

CFLAGS = -Wall -Wextra -Werror

MLX = -framework OpenGL -framework AppKit -lmlx

all : $(NAME)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@  

$(NAME) : $(OBJS) $(INCLUDE)
	$(CC) $(CFLAGS) $(OBJS) -I./include $(MLX) -L . -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

bonus : $(NAME)

.PHONY: clean fclean re all