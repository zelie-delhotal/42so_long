/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 03:28:36 by gdelhota          #+#    #+#             */
/*   Updated: 2025/04/24 22:18:56 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_move(t_game *game, char move)
{
	int	move_x;
	int	move_y;
	int	dest_x;
	int	dest_y;

	move_x = (move == 'D') - (move == 'A');
	move_y = (move == 'S') - (move == 'W');
	dest_x = game->player_pos[0] + move_x;
	dest_y = game->player_pos[1] + move_y;
	if (game->map[dest_y][dest_x] != '1')
	{
		game->player_pos[0] = dest_x;
		game->player_pos[1] = dest_y;
		//update_tile(game, dest_x, dest_y);
		draw_tile(game, dest_x - move_x, dest_y - move_y);
		draw_tile(game, dest_x, dest_y);
	}
}

int	key_up(int key, t_game *game)
{
	if (key == 'w')
		player_move(game, 'W');
	if (key == 'a')
		player_move(game, 'A');
	if (key == 's')
		player_move(game, 'S');
	if (key == 'd')
		player_move(game, 'D');
	if (key == 65307)
		mlx_loop_end(game->mlx);
	return (0);
}
