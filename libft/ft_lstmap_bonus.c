/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdelhota <gdelhota@student.42perpigna      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:19:24 by gdelhota          #+#    #+#             */
/*   Updated: 2024/11/13 19:22:53 by gdelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*last;
	void	*temp;

	res = NULL;
	while (lst && f)
	{
		temp = (*f)(lst->content);
		last = ft_lstnew(temp);
		if (!last)
		{
			(*del)(temp);
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, last);
		lst = lst->next;
	}
	return (res);
}
