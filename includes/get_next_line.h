/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:19:19 by gdelhota          #+#    #+#             */
/*   Updated: 2025/04/19 15:58:15 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# if BUFFER_SIZE <= 0
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int		trim_endline(char **s, char *buffer, int size);
char	*str_calloc(size_t n);
char	*strn_append(char *s1, char *s2, int n, char must_free);
char	*ft_strndup(char *s, int n);
void	ft_strncpy(char *src, char *dst, int n);
char	*get_next_line(int fd);
char	*get_next_line_no_br(int fd);

#endif
