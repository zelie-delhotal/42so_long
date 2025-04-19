/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:21:18 by gdelhota          #+#    #+#             */
/*   Updated: 2025/04/19 15:57:48 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	liberate(char **str)
{
	free(*str);
	*str = NULL;
}

int	trim_endline(char **s, char *buffer, int size)
{
	int			i;
	int			mem_size;
	char		*temp;
	static char	*mem = NULL;

	if (size && !mem)
		mem = str_calloc(BUFFER_SIZE);
	mem_size = ft_strlen(mem);
	if (!mem || (!size && !mem_size))
		return (0);
	temp = strn_append(mem, buffer, size, 0);
	size += mem_size;
	i = 0;
	while (i < size && temp[i] != '\n')
		i++;
	*s = strn_append(*s, temp, i + 1, 1);
	mem[0] = '\0';
	if (i < size)
		free(mem);
	if (i < size)
		mem = ft_strndup(&temp[i + 1], size - i - 1);
	if (!mem[0])
		liberate(&mem);
	return (free(temp), i - mem_size);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*line;
	int		bytes_read;

	if (fd < 0)
		return (NULL);
	buffer = str_calloc(BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	line = NULL;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
		return (free(buffer), NULL);
	while (trim_endline(&line, buffer, bytes_read) == BUFFER_SIZE)
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	free(buffer);
	return (line);
}

char	*get_next_line_no_br(int fd)
{
	char	*res;
	int		i;

	res = get_next_line(fd);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (res[i] != '\n')
		i++;
	res[i] = '\0';
	return (res);
}
