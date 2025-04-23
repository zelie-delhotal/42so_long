/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:49:42 by gdelhota          #+#    #+#             */
/*   Updated: 2025/04/23 18:32:30 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "libft.h"
#include "mlx.h"

typedef enum sprite_index
{
	BG, WALL, PLAYER, EXIT
}	e_sprite_index;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	void	**images;
	int		tile_width;
	int		tile_height;
	int		player_pos[2];
	char	**map;
}			t_game;

t_game	*game_init();
void	game_close(t_game *game);
char	**map_parser(char *filename);

#endif
