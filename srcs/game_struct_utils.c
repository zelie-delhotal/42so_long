/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_struct_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 01:40:54 by gdelhota          #+#    #+#             */
/*   Updated: 2025/04/25 01:33:34 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_images(t_game *g)
{
	void	**i;
	int		width;
	int		height;

	i = (void **) malloc(7 * sizeof(void *));
	if (i == NULL)
	{
		game_close(g);
		ft_error(1, "malloc aaah moment");
	}
	i[BG] = mlx_xpm_file_to_image(g->mlx, "img/wall.xpm", &width, &height);
	i[WALL] = mlx_xpm_file_to_image(g->mlx, "img/bg.xpm", &width, &height);
	i[P] = mlx_xpm_file_to_image(g->mlx, "img/p.xpm", &g->tile_w, &g->tile_h);
	i[ITEM] = mlx_xpm_file_to_image(g->mlx, "img/c.xpm", &width, &height);
	i[E_C] = mlx_xpm_file_to_image(g->mlx, "img/e_c.xpm", &width, &height);
	i[E_O] = mlx_xpm_file_to_image(g->mlx, "img/e_o.xpm", &width, &height);
	i[6] = NULL;
	g->images = i;
}

t_game	*game_init(void *mlx, char **map)
{
	t_game	*game;
	int		width;
	int		height;

	game = malloc(sizeof(t_game));
	game->mlx = mlx;
	game->collect_left = 0;
	set_images(game);
	height = 0;
	while (map[++height])
	{
		width = 0;
		while (map[height][++width])
		{
			if (map[height][width] == 'P')
				game->player_x = width;
			if (map[height][width] == 'P')
				game->player_y = height;
			game->collect_left += (map[height][width] == 'C');
		}
	}
	width = (width * game->tile_w) + 10;
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
