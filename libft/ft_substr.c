/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:33:18 by gdelhota          #+#    #+#             */
/*   Updated: 2024/11/13 19:33:20 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;

	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
		len = 0;
	res = ft_calloc(len + 1, 1);
	if (!res)
		return (0);
	i = 0;
	while (i < len && s[start + i])
	{
		res[i] = s[start + i];
		i++;
	}
	return (res);
}

/*#include <stdio.h>
int	main(int ac, char **av)
{
	if (ac > 2)
	{
		printf("%s", ft_substr(av[1], ft_atoi(av[2]), ft_atoi(av[3])));
	}
}*/
