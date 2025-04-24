/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:32:15 by gdelhota          #+#    #+#             */
/*   Updated: 2024/11/13 19:32:19 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	size;

	size = ft_strlen(s);
	while (size != 0 && s[size] != (char) c)
		size--;
	if (s[size] == (char) c)
		return ((char *) &s[size]);
	return (0);
}

/*#include <stdio.h>
int	main(int ac, char **av)
{
	if (ac > 0)
	{
		printf("%li\n", ft_strrchr(av[1], av[2][0]) - av[1]);
		printf("%s", ft_strrchr(av[1], av[2][0]));
	}
}*/
