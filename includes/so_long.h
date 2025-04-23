/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:49:42 by gdelhota          #+#    #+#             */
/*   Updated: 2025/04/23 21:31:15 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft.h"
#include "mlx.h"

typedef enum sprite
{
	BG, WALL, PLAYER, ITEM, EXIT
}	e_sprite;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	void	**images;
	int		tile_w;
	int		tile_h;
	int		x_offset;
	int		y_offset;
	int		player_pos[2];
	char	**map;
}			t_game;

t_game	*game_init();
void	game_close(t_game *game);
char	**map_parser(char *filename);

#endif
