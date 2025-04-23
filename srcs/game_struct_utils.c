/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_struct_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 01:40:54 by gdelhota          #+#    #+#             */
/*   Updated: 2025/04/23 19:16:36 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_images(t_game *g)
{
	void	**i;
	int		width;
	int		height;

	i = malloc(5 * sizeof(void*));
	i[BG] = mlx_xpm_file_to_image(g->mlx, "img/test_square.xpm", &g->tile_width, &g->tile_height);
	i[WALL] = mlx_xpm_file_to_image(g->mlx, "img/depot.xpm", &width, &height);
	i[PLAYER] = mlx_xpm_file_to_image(g->mlx, "img/depot.xpm", &width, &height);
	i[EXIT] = mlx_xpm_file_to_image(g->mlx, "img/depot.xpm", &width, &height);
	g->images = i;
}

t_game	*game_init(void *mlx, char **map)
{
	t_game	*game;

	game = malloc(sizeof(t_game*));
	game->mlx = mlx;
	game->map = map;
	game->window = mlx_new_window(game->mlx, 500, 500, "Logi Run");
	set_images(game);
	return (game);
}

void	destroy_images(t_game *game)
{
	int	i;

	if (game == NULL || game->images == NULL)
		return ;
	i = -1;
	while (game->images[++i] != NULL)
		mlx_destroy_image(game->mlx, game->images[i]);
}

void	game_close(t_game *game)
{
	if (game->window != NULL)
	{
		mlx_clear_window(game->mlx, game->window);
		mlx_destroy_window(game->mlx, game->window);
	}
	destroy_images(game);
	if (game->map != NULL)
		free_all((void **)game->map);
	if (game->mlx != NULL)
		mlx_destroy_display(game->mlx);
	free(game);
}
