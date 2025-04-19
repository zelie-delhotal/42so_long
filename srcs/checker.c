/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpignan.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:44:22 by gdelhota          #+#    #+#             */
/*   Updated: 2025/04/19 18:47:35 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <stdio.h>

char	**reachable_tiles(char **map, int x, int y, int width, int height)
{
	static char	**matrix = NULL;
	int			i;

	if (matrix == NULL)
	{
		matrix = (char **) ft_calloc(height + 1, sizeof(char *));
		i = -1;
		while (++i < height)
			matrix[i] = (char *) ft_calloc(width + 1, sizeof(char));
		matrix[y][x] = '1';
		reach_neighbors(map, x, y, width, height);
	}
	if (x <= 0 || y <= 0 || x >= width || y >= height || matrix[y][x] == '1'
			|| map[y][x] == '1')
		return (matrix);
	if ((matrix[y - 1][x] + matrix[y + 1][x] + matrix[y][x + 1] + matrix[y][x - 1]) != 0)
		matrix[y][x] = '1';
	if (matrix[y][x] == '1')
		reach_neighbors(map, x, y, width, height);
	return (matrix);
}

void	reach_neighbors(char **map, int x, int y, int width, int height)
{
	reachable_tiles(map, x + 1, y, width, height);
	reachable_tiles(map, x, y + 1, width, height);
	reachable_tiles(map, x - 1, y, width, height);
	reachable_tiles(map, x, y - 1, width, height);
}

static int	valid_path_exists(char **map, char **matrix)
{
	int	x;
	int	y;

	y = 0;
	while(map[++y])
	{
		x = 0;
		while (map[y][++x])
		{
			if ((map[y][x] == 'E' || map[y][x] == 'C') && matrix[y][x] == 0)
				return (0);
		}
	}
	return (1);
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
	//printf("x = %d y = %d walls = %d length = %d", x, y, wall_counter, length);
	return (x > 2 && y > 2 && wall_counter == length);
}

int	map_is_valid(char **map, int width, int height)
{
	int	x;
	int	y;
	char	**matrix;

	if (!map_is_rectangle(map))
		return (0);
	matrix = NULL;
	y = 0;
	while (map && map[++y])
	{
		x = 0;
		while (map[y][++x])
		{
			if (map[y][x] == 'P' && matrix == NULL)
				matrix = reachable_tiles(map, x, y, width, height);
			else if (ft_strchr("01CE", map[y][x]) == NULL)
			{
				write(2, "wrong chars\n", 12);
				return (free_all((void **)matrix), 0);
			}
		}
	}
	if (matrix != NULL && valid_path_exists(map, matrix))
		return (free_all((void **)matrix), 1);
	else
		return (free_all((void **)matrix), 0);
}
