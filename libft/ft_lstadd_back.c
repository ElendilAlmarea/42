/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:57:22 by yvanat            #+#    #+#             */
/*   Updated: 2019/10/20 17:48:00 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *neww)
{
	t_list	*tmp;

	if (!alst && neww)
		alst = &neww;
	else if (!(*alst) && neww)
		*alst = neww;
	else if (neww)
	{
		tmp = *alst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = neww;
		neww->next = NULL;
	}
}
