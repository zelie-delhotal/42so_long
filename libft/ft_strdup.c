/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:27:06 by gdelhota          #+#    #+#             */
/*   Updated: 2024/11/13 19:27:11 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	size_t	size;

	size = ft_strlen(s) + 1;
	res = malloc(size * sizeof(char));
	if (!res)
		return (0);
	ft_strlcpy(res, s, size);
	return (res);
}
