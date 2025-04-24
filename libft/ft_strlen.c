/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:30:01 by gdelhota          #+#    #+#             */
/*   Updated: 2025/04/19 17:29:16 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i * sizeof(char));
}

/*#include <stdio.h>
int main(int ac, char **av)
{
	if (ac > 0)
	{
		printf("%d", (int) ft_strlen(av[1]));
	}
}*/
