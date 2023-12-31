/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srajaoui <srajaoui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 03:11:00 by srajaoui          #+#    #+#             */
/*   Updated: 2023/09/19 03:11:05 by srajaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_header.h"

void	free_path(t_game *game)
{
	free(game->path_north_xpm);
	free(game->path_south_xpm);
	free(game->path_east_xpm);
	free(game->path_west_xpm);
}

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	free_xpm(int **tab, int x)
{
	int	i;

	i = 0;
	while (i < x)
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
	free_xpm(game->north.xpm, game->north.length);
	free_tab(game->north.colors);
	free_xpm(game->south.xpm, game->south.length);
	free_tab(game->south.colors);
	free_xpm(game->east.xpm, game->east.length);
	free_tab(game->east.colors);
	free_xpm(game->west.xpm, game->west.length);
	free_tab(game->west.colors);
	free_xpm(game->screen, SCREEN_LENGTH);
	free(game->map.map);
	exit (0);
}

void	free_tmp_value(t_tmp *tmp)
{
	free_tab(tmp->north_xpm);
	free_tab(tmp->south_xpm);
	free_tab(tmp->east_xpm);
	free_tab(tmp->west_xpm);
}
