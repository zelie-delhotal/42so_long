/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:26:35 by gdelhota          #+#    #+#             */
/*   Updated: 2025/04/19 15:26:30 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*str_calloc(size_t n)
{
	size_t	i;
	char	*res;

	res = malloc(n);
	if (!res)
		return (NULL);
	i = 0;
	while (i < n)
	{
		res[i] = 0;
		i++;
	}
	return (res);
}

char	*ft_strndup(char *s, int n)
{
	char	*res;
	int		i;

	res = ft_calloc((n + 1), sizeof(char));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < n)
		res[i] = s[i];
	return (res);
}

char	*strn_append(char *s1, char *s2, int n, char must_free)
{
	int		i;
	int		j;
	char	*res;

	if (!s1)
		return (ft_strndup(s2, n));
	if (!s2)
		return (s1);
	res = (char *) malloc(ft_strlen(s1) + n + 1);
	if (!res)
		return (NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	if (must_free)
		free(s1);
	j = -1;
	while (++j < n && s2[j])
		res[i + j] = s2[j];
	res[i + j] = 0;
	return (res);
}
