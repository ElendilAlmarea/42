/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:36:24 by yvanat            #+#    #+#             */
/*   Updated: 2019/10/20 17:48:37 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *neww)
{
	t_list	*tmp;

	if (!alst && neww)
		alst = &neww;
	else if (!(*alst) && neww)
		*alst = neww;
	else if (neww)
	{
		tmp = *alst;
		neww->next = tmp;
		tmp = neww;
	}
}
