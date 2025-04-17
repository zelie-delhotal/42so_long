/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:05:16 by gdelhota          #+#    #+#             */
/*   Updated: 2025/04/17 18:54:07 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "parser.h"

char	**expand_map(char ***map, char *line, int size)
{
	char	**res;
	int		i;

	res = malloc((size + 1) * sizeof(char *));
	i = 0;
	while (i < size)
	{
		res[i] = (*map)[i];
		i++;
	}
	res[i] = line;
	free(*map);
	return (res);
}

char	**map_parser(char *filename)
{
	char	**map;
	char	*curr_line;
	int		fd;
	int		i;

	i = ft_strlen(filename) - 4;
	if (ft_strncmp(".ber", &filename[ft_strlen(filename) - 5], 4) != 0)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	curr_line = get_next_line(fd);
	map = &curr_line;
	i = 1;
	while (curr_line != NULL)
	{
		curr_line = get_next_line(fd);
		map = expand_map(&map, curr_line, i);
		i++;
	}
	return (map);
}

int	map_is_valid_rectangle(char **map)
{
	int	x;
	int	y;
	int	length;
	int	wall_counter;

	size = -1;
	while (map[0] && map[0][++length])
	{
		if (map[0][size] != '1')
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
	return (x > 2 && y > 2 && wall_counter == length - 1);
}

int	valid_path_exists(char **map, int *start_pos)
{
	static char	**reachable_tiles;
}

int	map_is_valid(char **map)
{
	int	x;
	int	y;
	int	start_pos[2];

	start_pos = NULL;
	y = 0;
	while (map && map[++y])
	{
		x = 0;
		while (map[y][++x])
		{
			if (map[y][x] == 'P' && start_pos = NULL)
				start_pos = {x, y};
			else if (ft_strchr("01CE", map[y][x]) == NULL)
				return (0);
		}
	}
	if (start_pos = NULL)
		return (0);
	return (map_is_valid_rectangle(map) && valid_path_exists(map, start_pos));
}
