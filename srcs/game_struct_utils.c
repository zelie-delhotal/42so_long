/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_struct_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 01:40:54 by gdelhota          #+#    #+#             */
/*   Updated: 2025/04/24 22:00:47 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_images(t_game *g)
{
	void	**i;
	int		width;
	int		height;

	i = (void **) malloc(6 * sizeof(void *));
	if (i == NULL)
	{
		game_close(g);
		ft_error(1, "malloc aaah moment");
	}
	i[BG] = mlx_xpm_file_to_image(g->mlx, "img/bg.xpm", &g->tile_w, &g->tile_h);
	i[WALL] = mlx_xpm_file_to_image(g->mlx, "img/wall.xpm", &width, &height);
	i[P] = mlx_xpm_file_to_image(g->mlx, "img/p.xpm", &width, &height);
	i[ITEM] = mlx_xpm_file_to_image(g->mlx, "img/c.xpm", &width, &height);
	i[EXIT] = mlx_xpm_file_to_image(g->mlx, "img/e.xpm", &width, &height);
	i[5] = NULL;
	g->images = i;
}

t_game	*game_init(void *mlx, char **map)
{
	t_game	*game;
	int		width;
	int		height;

	game = malloc(sizeof(t_game));
	game->mlx = mlx;
	game->map = map;
	set_images(game);
	height = 0;
	while (map[++height])
	{
		width = 1;
		while (map[height][width] && map[height][width] != 'P')
			width++;
		if (map[height][width] == 'P')
			game->player_pos[0] = width;
		if (map[height][width] == 'P')
			game->player_pos[1] = height;
	}
	width = (ft_strlen(map[0]) * game->tile_w) + 10;
	height = (height * game->tile_h) + 10;
	game->window = mlx_new_window(game->mlx, width, height, "Logi Run");
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
	free(game->images);
}

int	game_close(t_game *game)
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
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
	return (0);
}
