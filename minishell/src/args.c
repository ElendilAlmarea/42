/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 14:50:21 by yvanat            #+#    #+#             */
/*   Updated: 2020/03/07 14:50:44 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_args	*argsnew(void)
{
	t_args	*new;

	if (!(new = malloc(sizeof(t_args))))
		return (NULL);
	new->in = -1;
	new->out = -1;
	new->m = (t_magic){NULL, NULL, -1};
	new->next = NULL;
	return (new);
}

void	argsadd(t_args **cmd, t_args *new)
{
	t_args	*tmp;

	tmp = *cmd;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->next = NULL;
}

void	argsclear(t_args *node)
{
	t_args	*tmp;

	if (!node)
		return ;
	while (node)
	{
		tmp = node->next;
		lstclear(node->lst);
		free(node);
		node = tmp;
	}
}
