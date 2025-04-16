/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:05:16 by gdelhota          #+#    #+#             */
/*   Updated: 2025/04/16 18:41:24 by gdelhota         ###   ########.fr       */
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
