/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:29:20 by gdelhota          #+#    #+#             */
/*   Updated: 2024/11/13 19:29:25 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	j = 0;
	if (size <= i)
		return (size + ft_strlen(src));
	while (src[j] && i + j < size - 1)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (i + ft_strlen(src));
}

/*#include <bsd/string.h>
#include <stdlib.h>
#include <stdio.h>
int main(int ac, char **av)
{
	if (ac > 2)
	{
		char	*d;
		d = malloc(atoi(av[1]) * sizeof(char));
		strcpy(d, av[2]);
		printf("cat : %d \n %s\n", (int)strlcat(d, av[3], atoi(av[4])), d);
		strcpy(d, av[2]);
		printf("ft_cat : %d \n %s\n", (int)ft_strlcat(d, av[3], atoi(av[4])), d);
	}
}*/
