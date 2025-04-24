/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:24:06 by gdelhota          #+#    #+#             */
/*   Updated: 2024/11/13 19:24:26 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d_cast;
	unsigned char	*s_cast;
	size_t			i;

	d_cast = (unsigned char *)dest;
	s_cast = (unsigned char *)src;
	i = 0;
	if (src < dest)
	{
		while (n-- > 0)
		{
			d_cast[n] = s_cast[n];
		}
	}
	else if (dest < src)
	{
		while (i < n)
		{
			d_cast[i] = s_cast[i];
			i++;
		}
	}
	return (dest);
}
