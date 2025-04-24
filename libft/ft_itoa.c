/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:16:03 by gdelhota          #+#    #+#             */
/*   Updated: 2024/11/13 19:16:10 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_int_size(int n)
{
	if (n < 10 && n >= 0)
		return (1);
	if (n > -10 && n < 0)
		return (2);
	return (ft_int_size(n / 10) + 1);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		size;
	long	cast;

	size = ft_int_size(n);
	res = (char *) malloc((size + 1) * sizeof(char));
	if (!res)
		return (0);
	res[size] = 0;
	cast = (long) n;
	if (cast < 0)
	{
		cast = -cast;
		res[0] = '-';
	}
	if (cast == 0)
		res[0] = '0';
	while (cast > 0)
	{
		res[--size] = (cast % 10) + '0';
		cast /= 10;
	}
	return (res);
}

/*#include <stdio.h>
int	main(int ac, char **av)
{
	if (ac > 0)
	{
		printf("%s", ft_itoa(ft_atoi(av[1])));
	}
}*/
