#include "../../includes/cub3d_header.h"
	
void	free_tab(char **tab)
{
	int i;

	i = -1;
	while(tab[++i])
		free(tab[i]);
	free(tab);
}

void	free_xpm(int **tab, int x)
{
	int i;

	i = 0;
	while(i < x)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_graphics(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img.img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	mlx_destroy_image(game->map.mlx, game->map.img.img);
	mlx_destroy_window(game->map.mlx, game->map.win);
	mlx_destroy_display(game->map.mlx);
	free(game->map.mlx);
	free_xpm(game->wall.xpm, game->wall.length);
	free_tab(game->wall.colors);
	free_xpm(game->door.xpm, game->door.length);
	free_tab(game->door.colors);
	exit (0);
}