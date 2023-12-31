/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_header.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srajaoui <srajaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 02:40:29 by srajaoui          #+#    #+#             */
/*   Updated: 2023/09/19 02:40:33 by srajaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_HEADER_H
# define CUB3D_HEADER_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "minilibx-linux/mlx.h"

# define ESCAPE 65307

# define SCREEN_WIDTH 1280
# define SCREEN_LENGTH 720
# define BACKGROUND 0x8c8e8a
# define PLAYER 0x0f056b
# define WALL 0xffffff
# define DOOR_OPEN 0x80e56a
# define DOOR_CLOSE 0xdc1b1c

# define PI 3.1415926535
# define P2 PI / 2
# define P3 3 * PI / 2
# define DR 0.0174533

# define MOUSE_X SCREEN_WIDTH / 2
# define MOUSE_Y SCREEN_LENGTH / 2

typedef struct s_xpm {
	char	**colors;
	int		**xpm;
	int		width;
	int		length;
	int		colors_number;
	int		charactere_per_color;
}		t_xpm;

typedef struct s_tmp {
	t_xpm	north;
	t_xpm	south;
	t_xpm	east;
	t_xpm	west;
	int		northtxt;
	int		southtxt;
	int		easttxt;
	int		westtxt;
	char	**north_xpm;
	char	**south_xpm;
	char	**east_xpm;
	char	**west_xpm;
}		t_tmp;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

typedef struct s_map {
	void	*mlx;
	void	*win;
	int		*map;
	int		width;
	int		length;
	int		unit;
	t_data	img;
}		t_map;

typedef struct s_math
{
	int		map_point;
	int		map_x;
	int		map_y;
	int		ray;
	int		dof;
	int		weren;
	int		weres;
	int		weree;
	int		werew;
	float	ray_angle;
	float	x_offset;
	float	y_offset;
	float	ray_x;
	float	ray_y;
	float	dis_t;
	float	dis_h;
	float	dis_v;
	float	horizontal_x;
	float	vertical_x;
	float	horizontal_y;
	float	vertical_y;
	float	atan;
	float	ntan;
	float	lineh;
	float	lineo;
	float	were_f;
	float	correction_angle;
}		t_math;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		**screen;
	int		spawn_x;
	int		spawn_y;
	float	p_x;
	float	p_y;
	float	p_dx;
	float	p_dy;
	float	p_a;
	t_xpm	north;
	t_xpm	south;
	t_xpm	east;
	t_xpm	west;
	char	*path_north_xpm;
	char	*path_south_xpm;
	char	*path_east_xpm;
	char	*path_west_xpm;
	int		floor;
	int		ceiling;
	t_map	map;
	t_data	img;
	t_math	math;
}		t_game;

/**********xpm_parsing**********/

char	*get_flat(int map);
char	*cut_line(char *buff);
char	**ft_image_to_char(int map);
char	*get_line(int xpm, char *buff);
void	pars_close(t_tmp *tmp);
void	tab_in_xpm(t_tmp *tmp);
void	check_color(t_tmp *tmp);
void	check_square(t_tmp *tmp);
void	init_assign(t_game *game);
void	pars_open(t_tmp *tmp, t_game *game);
void	atoi_for_xpm(char *str, t_xpm *xpm);
void	xpm_to_int(char **xpm_char, t_xpm *xpm);
void	xpm_to_char(char **xpm_char, t_xpm *xpm);
void	place_colors(char **xpm_info, t_xpm *xpm);
int		atoi_hexa(char *str);
int		get_color(t_xpm *xpm, char **xpm_char, int x, int y);

/**********map_parsing**********/

char	*put_path(char *path_brut);
char	**put_char_map(t_game *game, char **map_brut, int start \
	, char **map_char);
void	map_verify(t_game *game, char *path);
void	get_map(t_game *game, char **map_brut);
void	all_info(t_game *game, char **map_brut);
void	map_error(t_game *game, char **map_char);
void	map_error(t_game *game, char **map_char);
void	check_map(t_game *game, char **map_char);
void	put_in_int(t_game *game, char **map_char);
void	get_texture(t_game *game, char **map_brut);
void	get_backgroud(t_game *game, char **map_brut);
void	check_info(t_game *game, char **map_char, int y, int x);
void	assign_spawn(t_game *game, char **map_char, int y, int x);
int		get_hexa(char *number);
int		ft_atoi(char *str, int i);
int		rgb_to_hex(int r, int g, int b);
int		were_start(t_game *game, char **map_brut);
int		map_width(t_game *game, char **map_brut, int start);
int		map_length(t_game *game, char **map_brut, int start);
int		go_set_spawn(t_game *game, char **map_char, int y, int x);
int		go_set_spawn_sup(t_game *game, char **map_char, int y, int x);

/********game_essential********/

void	game_start(t_game *game);
void	screen_alloc(t_game *game);
void	graphic_management(t_game *game);
int		cross_exit(t_game *game);
int		esc_exit(int keycode, t_game *game);

/**********interaction**********/

void	look_left(t_game *game, t_data *img);
void	look_right(t_game *game, t_data *img);
void	go_up(t_game *game, t_data *img, t_data *img_map);
void	go_left(t_game *game, t_data *img, t_data *img_map);
void	go_down(t_game *game, t_data *img, t_data *img_map);
void	go_right(t_game *game, t_data *img, t_data *img_map);
void	open_east(t_game *game, t_data *img, t_data *img_map);
void	open_west(t_game *game, t_data *img, t_data *img_map);
void	open_north(t_game *game, t_data *img, t_data *img_map);
void	open_south(t_game *game, t_data *img, t_data *img_map);
void	orientation(t_game *game, t_data *img, t_data *img_map);
int		code_moove(int keycode, void *gm);
int		mouse_moove(int mouse_x, int mouse_y, void *gm);

/**********xmini_map**********/

void	put_map(t_game *game, t_data *img);
void	put_player(t_game *game, t_data *img);
void	go_wall(int x, int y, t_data *img, int code);
void	gray_screen(t_data *img, int width, int length);
void	go_player(t_game *game, int x, int y, t_data *img);
void	aff_screen(t_game *game, t_data *img, int code, int size);

/*************image*************/

void	tab_to_image(t_game *game, t_data *img);
void	my_mlx_pixel_put(t_data *data, int x, int y, int colors);

/**********free_value**********/

void	free_tab(char **tab);
void	free_path(t_game *game);
void	free_xpm(int **tab, int x);
void	free_tmp_value(t_tmp *tmp);
void	free_graphics(t_game *game);

/**********raycasting**********/

float	dist(float ax, float ay, float bx, float by);
void	ray_x(t_game *game);
void	ray_y(t_game *game);
void	were_x(t_game *game);
void	were_y(t_game *game);
void	do_ray(t_game *game);
void	set_angle(t_game *game);
void	ray_x_inforsup(t_game *game);
void	ray_y_inforsup(t_game *game);
void	were_put_pixel(t_game *game);
void	wich_is_bigger(t_game *game);
void	angle_correction(t_game *game);
void	print_floor(t_game *game, int pixel_count, int z, int gray);
void	print_texture_east(t_game *game, int pixel_count, int z, int gray);
void	print_texture_west(t_game *game, int pixel_count, int z, int gray);
void	print_texture_north(t_game *game, int pixel_count, int z, int gray);
void	print_texture_south(t_game *game, int pixel_count, int z, int gray);
int		print_line(t_game *game, int pixel_count);
int		print_sky(t_game *game, int pixel_count, int z, int gray);

/*************utils*************/

size_t	ft_strlen(char *str);
char	**st_split(char *s, char c);
char	**ft_split(char *s, char c);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*word_dup(char *str, int start, int finish);

#endif
