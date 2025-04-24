/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:31:11 by gdelhota          #+#    #+#             */
/*   Updated: 2024/11/13 19:31:12 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	i;

	if (!f)
		return (0);
	res = malloc(ft_strlen(s) + 1);
	if (!res)
		return (0);
	i = -1;
	while (s[++i])
		res[i] = (*f)(i, s[i]);
	res[i] = 0;
	return (res);
}
