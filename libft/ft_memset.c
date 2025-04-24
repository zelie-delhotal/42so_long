/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:24:41 by gdelhota          #+#    #+#             */
/*   Updated: 2024/11/13 19:24:52 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*res;

	res = (char *) s;
	i = 0;
	while (i < n)
	{
		res[i] = (unsigned char) c;
		i++;
	}
	return (s);
}

/*#include <stdio.h>
#include <string.h>
int main(void)
{
	char *s = (char *) malloc(32);
	s = (char *) ft_memset(s, 0, 32);
	s = (char *) ft_memset(s, 'A', 31);
	s = (char *) ft_memset(s, 'g', 4);
	printf("%s\n", s);
}*/
