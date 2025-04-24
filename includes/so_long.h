/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 19:49:42 by gdelhota          #+#    #+#             */
/*   Updated: 2025/04/25 01:30:16 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"

typedef enum e_sprite
{
	BG,
	WALL,
	P,
	ITEM,
	E_C,
	E_O
}	t_sprite;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	void	**images;
	int		tile_w;
	int		tile_h;
	int		player_x;
	int		player_y;
	int		collect_left;
	int		exit_x;
	int		exit_y;
	char	**map;
}			t_game;

t_game	*game_init(void *mlx, char **map);
int		game_close(t_game *game);
char	**map_parser(char *filename);
void	draw_tile(t_game *game, int x_tile, int y_tile);
int		key_up(int keycode, t_game *game);

#endif
