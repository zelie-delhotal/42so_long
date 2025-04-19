/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:05:16 by gdelhota          #+#    #+#             */
/*   Updated: 2025/04/19 16:37:25 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "parser.h"
#include <stdio.h>

static char	**expand_map(char ***map, char *line, int size)
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
	if (map)
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
	if (i < 1 || ft_strncmp(".ber", &filename[ft_strlen(filename) - 4], 4) != 0)
		ft_error(1, "File format error");
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error(1, "File open error");
	i = 0;
	map = NULL;
	curr_line = get_next_line_no_br(fd);
	while (curr_line != NULL)
	{
		map = expand_map(&map, curr_line, i);
		curr_line = get_next_line_no_br(fd);
		i++;
	}
	map = expand_map(&map, NULL, i);
	if (map_is_valid(map, ft_strlen(map[0]), i))
		return (map);
	ft_error(1, "Map Error");
	return (NULL);
}
