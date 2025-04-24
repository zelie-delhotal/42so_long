/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:46:29 by gdelhota          #+#    #+#             */
/*   Updated: 2025/04/25 01:24:02 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>

int		map_is_valid(char **map, int width, int height);
void	reach_neighbors(char **map, int x, int y, int *map_size);
char	**reachable_tiles(char **map, int x, int y, int *map_size);

#endif
