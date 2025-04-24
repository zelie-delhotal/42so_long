/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 03:28:36 by gdelhota          #+#    #+#             */
/*   Updated: 2025/04/25 01:10:35 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_tile(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = '0';
		if (--game->collect_left == 0)
			draw_tile(game, game->exit_x, game->exit_y);
	}
	else if (game->map[y][x] == 'E' && game->collect_left == 0)
		mlx_loop_end(game->mlx);
}

void	player_move(t_game *game, char move)
{
	static int	move_count = 0;
	int			move_x;
	int			move_y;
	int			dest_x;
	int			dest_y;

	move_x = (move == 'D') - (move == 'A');
	move_y = (move == 'S') - (move == 'W');
	dest_x = game->player_x + move_x;
	dest_y = game->player_y + move_y;
	if (game->map[dest_y][dest_x] != '1')
	{
		ft_putnbr_fd(++move_count, 1);
		ft_putstr_fd(" move(s)\n", 1);
		game->player_x = dest_x;
		game->player_y = dest_y;
		update_tile(game, dest_x, dest_y);
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
