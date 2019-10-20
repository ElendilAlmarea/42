/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:36:24 by yvanat            #+#    #+#             */
/*   Updated: 2019/10/20 14:50:21 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *neww)
{
	t_list	*tmp;

	if (neww && *alst && alst)
	{
		tmp = *alst;
		neww->next = tmp;
		tmp = neww;
	}
}
