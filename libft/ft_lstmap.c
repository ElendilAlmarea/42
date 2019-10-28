/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:06:32 by yvanat            #+#    #+#             */
/*   Updated: 2019/10/28 14:09:12 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*first_tmp;
	t_list	*tmp;

	if (!lst || !f || !del)
		return (NULL);
	tmp = lst;
	if (!(first = ft_lstnew((*f)(tmp->content))))
		return (NULL);
	first_tmp = first;
	tmp = tmp->next;
	while (tmp)
	{
		if (!(first_tmp->next = ft_lstnew((*f)(tmp->content))))
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		first_tmp = first_tmp->next;
		tmp = tmp->next;
	}
	return (first);
}
