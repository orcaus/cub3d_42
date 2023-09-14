#include "../../includes/cub3d_header.h"

void	look_left(t_game *game, t_data *img)
{
	gray_screen(&game->img, SCREEN_WIDTH, SCREEN_LENGTH);
	game->p_a -= 0.05;
	if (game->p_a < 0)
		game->p_a += 2 * PI;
	game->p_dx = cos(game->p_a) * 5;
	game->p_dy = sin(game->p_a) * 5;
	do_ray(game, img);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}

void	look_right(t_game *game, t_data *img)
{
	gray_screen(&game->img, SCREEN_WIDTH, SCREEN_LENGTH);
	game->p_a += 0.05;
	if (game->p_a > 2 * PI)
		game->p_a -= 2 * PI;
	game->p_dx = cos(game->p_a) * 5;
	game->p_dy = sin(game->p_a) * 5;
	do_ray(game, img);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
}

void	orientation(t_game *game, t_data *img, t_data *img_map)
{
	if (game->p_a / PI > 0.25 && game->p_a / PI < 0.75)
		open_south(game, img, img_map);
	else if (game->p_a / PI > 1.25 && game->p_a / PI < 1.75)
		open_north(game, img, img_map);
	else if (game->p_a / PI > 0.75 && game->p_a / PI < 1.25)
		open_west(game, img, img_map);
	else if ((game->p_a / PI > 1.75 && game->p_a / PI <= 1.999999999) || (game->p_a / PI >= 0 && game->p_a / PI < 0.25))
		open_east(game, img, img_map);
}