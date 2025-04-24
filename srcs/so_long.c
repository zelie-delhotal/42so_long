/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:01:51 by gdelhota          #+#    #+#             */
/*   Updated: 2025/04/24 21:37:11 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_tile(t_game *game, int x_tile, int y_tile)
{
	void	*img;
	int		x;
	int		y;

	img = game->images[BG];
	x = (x_tile * game->tile_w) + game->x_offset;
	y = (y_tile * game->tile_h) + game->y_offset;
	mlx_put_image_to_window(game->mlx, game->window, img, x, y);
	if (game->map[y_tile][x_tile] == '1')
		img = game->images[WALL];
	else if (game->map[y_tile][x_tile] == 'E')
		img = game->images[EXIT];
	else if (game->map[y_tile][x_tile] == 'C')
		img = game->images[ITEM];
	mlx_put_image_to_window(game->mlx, game->window, img, x, y);
	if (x_tile == game->player_pos[0] && y_tile == game->player_pos[1])
		mlx_put_image_to_window(game->mlx, game->window, game->images[P], x, y);
}

void	draw_map(t_game *game)
{
	int	x;
	int	y;
	//int	win_w;
	//int	win_h;

	game->x_offset = 5;
	game->y_offset = 5;
	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
			draw_tile(game, x, y);
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
	mlx_hook(game->window, 17, 2, mlx_loop_end, game->mlx);
	mlx_key_hook(game->window, key_up, game);
	mlx_loop(mlx);
	game_close(game);
	return (0);
}
