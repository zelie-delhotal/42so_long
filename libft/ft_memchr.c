/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:21:35 by gdelhota          #+#    #+#             */
/*   Updated: 2024/11/13 19:21:46 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cast;

	if (n == 0)
		return (0);
	cast = (unsigned char *) s;
	i = 0;
	while (i < n - 1 && cast[i] != (unsigned char) c)
		i++;
	if (cast[i] == (unsigned char) c)
		return ((void *) &cast[i]);
	return (0);
}

/*#include <stdio.h>
int	main(int ac, char **av)
{
	if (ac > 0)
		printf("%s", (char *) ft_memchr(av[1], av[2][0], ft_atoi(av[3])));
}*/
