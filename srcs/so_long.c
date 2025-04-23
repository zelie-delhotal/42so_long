/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:01:51 by gdelhota          #+#    #+#             */
/*   Updated: 2025/04/23 22:12:09 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_sprite(t_game *game, e_sprite sprite, int x_tile, int y_tile)
{
	void	*img;
	int		x;
	int		y;

	img = game->images[sprite];
	x = (x_tile * game->tile_w) + game->x_offset;
	y = (y_tile * game->tile_h) + game->y_offset;
	mlx_put_image_to_window(game->mlx, game->window, img, x, y);
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			draw_sprite(game, BG, x, y);
			if (game->map[y][x] == '1')
				draw_sprite(game, WALL, x, y);
			else if (game->map[y][x] == 'E')
				draw_sprite(game, EXIT, x, y);
			else if (game->map[y][x] == 'C')
				draw_sprite(game, ITEM, x, y);
			else if (game->map[y][x] == 'P')
			{
				game->map[y][x] = '0';
				game->player_pos[0] = x;
				game->player_pos[1] = y;
			}
			if (x == game->player_pos[0] && y == game->player_pos[1])
				draw_sprite(game, PLAYER, x, y);
		}
	}
}

int	main(int ac, char **av)
{
	t_game	*game;
	char	**map;
	void	*mlx;

	if (ac < 2)
		exit(1);
	map = map_parser(av[1]);
	if (map == NULL)
		exit(0);
	mlx = mlx_init();
	game = game_init(mlx, map);
	draw_map(game);
	mlx_loop(mlx);
}
