/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:44:22 by gdelhota          #+#    #+#             */
/*   Updated: 2025/04/25 01:27:27 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	**reachable_tiles(char **map, int x, int y, int *map_size)
{
	static char	**mat = NULL;
	int			width;
	int			height;
	int			i;

	width = map_size[0];
	height = map_size[1];
	if (mat == NULL)
	{
		mat = (char **) ft_calloc(height + 1, sizeof(char *));
		i = -1;
		while (++i < height)
			mat[i] = (char *) ft_calloc(width + 1, sizeof(char));
		mat[y][x] = '1';
		reach_neighbors(map, x, y, map_size);
	}
	if (x <= 0 || y <= 0 || x >= width || y >= height || mat[y][x] == '1'
			|| map[y][x] == '1')
		return (mat);
	if ((mat[y - 1][x] + mat[y + 1][x] + mat[y][x + 1] + mat[y][x - 1]) != 0)
		mat[y][x] = '1';
	if (mat[y][x] == '1')
		reach_neighbors(map, x, y, map_size);
	return (mat);
}

void	reach_neighbors(char **map, int x, int y, int *map_size)
{
	reachable_tiles(map, x + 1, y, map_size);
	reachable_tiles(map, x, y + 1, map_size);
	reachable_tiles(map, x - 1, y, map_size);
	reachable_tiles(map, x, y - 1, map_size);
}

static int	level_is_ok(char **map, char **mat)
{
	int	x;
	int	y;
	int	collectible_count;
	int	exit_count;

	if (mat == NULL)
		return (0);
	collectible_count = 0;
	exit_count = 0;
	y = 0;
	while (map[++y])
	{
		x = 0;
		while (map[y][++x])
		{
			if ((map[y][x] == 'E' || map[y][x] == 'C') && mat[y][x] == 0)
				return (0);
			collectible_count += (map[y][x] == 'C');
			exit_count += (map[y][x] == 'E');
		}
	}
	return (exit_count == 1 && collectible_count > 0);
}

static int	map_is_rectangle(char **map)
{
	int	x;
	int	y;
	int	length;
	int	wall_counter;

	length = -1;
	while (map[0] && map[0][++length])
	{
		if (map[0][length] != '1')
			return (0);
	}
	y = 0;
	while (map[++y] != NULL)
	{
		wall_counter = 0;
		x = -1;
		while (map[y][++x])
			wall_counter += (map[y][x] == '1');
		if (x != length || map[y][0] != '1' || map[y][x - 1] != '1')
			return (0);
	}
	return (x > 2 && y > 2 && wall_counter == length);
}

int	map_is_valid(char **map, int width, int height)
{
	int		x;
	int		y;
	int		res;
	int		map_size[2];
	char	**mat;

	if (!map_is_rectangle(map))
		return (0);
	mat = NULL;
	map_size[0] = width;
	map_size[1] = height;
	y = 0;
	while (map && map[++y])
	{
		x = 0;
		while (map[y][++x])
		{
			if (map[y][x] == 'P' && mat == NULL)
				mat = reachable_tiles(map, x, y, map_size);
			else if (ft_strchr("01CE", map[y][x]) == NULL)
				return (free_all((void **)mat), 0);
		}
	}
	res = level_is_ok(map, mat);
	return (free_all((void **)mat), res);
}
