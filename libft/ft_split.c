/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:26:10 by gdelhota          #+#    #+#             */
/*   Updated: 2024/11/13 19:26:11 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(const char *s, char sep)
{
	int		count;
	int		in_word;
	size_t	i;

	count = 0;
	in_word = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == sep)
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static	char	**ft_free_all(char **s, int count)
{
	while (count >= 0)
		free(s[count--]);
	free(s);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		count;
	int		i;
	int		j;

	res = (char **) malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!res)
		return (0);
	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
			res[count++] = ft_substr(s, j, (i - j));
		if (count > 0 && !res[count - 1])
			return (ft_free_all(res, count - 1));
	}
	res[count] = 0;
	return (res);
}

/*#include <stdio.h>
int main(int ac, char **av)
{
	char	**test;
	int		i;

	if(ac > 1)
	{
		test = ft_split(av[1], av[2][0]);
		i = 0;
		while(test[i])
		{
			printf("%s\n", test[i]);
			i++;
		}
	}
}*/
