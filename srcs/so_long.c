/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:01:51 by gdelhota          #+#    #+#             */
/*   Updated: 2025/04/23 19:15:43 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*void	draw_map(t_game *game, int tile_width, int tile_height)
{
	
}*/

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
	mlx_put_image_to_window(game->mlx, game->window, game->images[BG], 0 , 0);
	mlx_put_image_to_window(game->mlx, game->window, game->images[PLAYER], 50 , 50);
	mlx_loop(mlx);
}
