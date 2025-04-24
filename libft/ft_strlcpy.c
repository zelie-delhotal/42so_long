/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:29:39 by gdelhota          #+#    #+#             */
/*   Updated: 2024/11/13 19:29:45 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = -1;
	while (src[++i] && i < size - 1)
		dst[i] = src[i];
	dst[i] = '\0';
	return (ft_strlen(src));
}

/*#include <stdio.h>
#include <bsd/string.h>
int main(int ac, char **av)
{
	if (ac > 1)
	{
		char *dst = malloc(32 * sizeof(char));
		int size = ft_strlcpy(dst, av[1], ft_atoi(av[2]));
		printf("ft_strlcpy : %s %d \n", dst, size);
		dst[0] = 0;
		size = strlcpy(dst, av[1], ft_atoi(av[2]));
		printf("strlcpy : %s %d \n", dst, size);
		free(dst);
	}
}*/
