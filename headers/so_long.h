#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include "mlx.h"

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define ESC 53

typedef struct s_map
{
	int		height;
	int		width;
	char	**buf;
}	t_map;

typedef struct s_image
{
	int		width;
	int		height;
	void	*image;
	char	*data;
	int		size;
	int		bpp;
	int		endian;
}	t_image;

typedef struct s_lon
{
	void	*mlx;
	void	*mlx_win;
	int		height;
	int		width;
	int		steps;
	int		x;
	int		y;
	int		x_v;
	int		y_v;
	int		f;
	int		ex;
	int		spr;
	int		count_eat;
	t_map	map;
	t_image	*image;
	t_image	*player;
	t_image	*floor;
	t_image	*face;
	t_image	*wall;
	t_image	*sprite;
	t_image	*door;
	t_image	*enemy;
}	t_lon;

typedef struct s_gl
{
	int			bytes_read;
	char		*linebreak;
	char		*buff;
	char		*temp;
}	t_gl;

void	get_map(char **argv, t_lon *lon);
void	draw_map(t_lon *lon);
int		get_width(t_lon *lon);
int		check_map(t_lon *lon);
void	movements(t_lon *lon, int x, int y);

int		check_wall_n(t_lon *lon);
int		check_wall_s(t_lon *lon);
int		check_wall_w(t_lon *lon);
int		check_wall_e(t_lon *lon);

int		count_E(t_lon *lon);
int		count_C(t_lon *lon);
int		count_P(t_lon *lon);

char	ft_check(char c, const char *set);
int		ft_strlen(const char *str);
int		get_next_line(int fd, char **line);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(char const *string, int symbol);
char	*ft_strdup(const char *str);
char	*ft_strcpy(char *dst, char *src);
void	ft_putchar(char c, int fd);
void	ft_putnbr(long int n);
void	ft_putstr(char *str, int fd);
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	set_new(t_lon *lon, t_image *image, int y, int x);
void	check_move_c(t_lon *lon, int x, int y);
void	check_move_zero(t_lon *lon, int x, int y);
void	move_en(t_lon *lon, int x, int y);
void	paint_step(t_lon *lon);
void	err_exit(char *str);
char	*ft_itoa(int n);
#endif