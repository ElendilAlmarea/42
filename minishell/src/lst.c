/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 05:27:50 by yvanat            #+#    #+#             */
/*   Updated: 2020/03/07 14:50:41 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lst	*lstnew(void)
{
	t_lst	*new;

	if (!(new = malloc(sizeof(t_lst))))
		return (NULL);
	new->next = NULL;
	return (new);
}

void	lstadd(t_lst **cmd, t_lst *new)
{
	t_lst	*tmp;

	tmp = *cmd;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->next = NULL;
}

void	lstclear(t_lst *node)
{
	t_lst	*tmp;

	if (!node)
		return ;
	if (!node)
		return ;
	while (node)
	{
		tmp = node->next;
		if (node->text)
			free(node->text);
		free(node);
		node = tmp;
	}
}
