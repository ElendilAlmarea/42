/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 14:45:48 by yvanat            #+#    #+#             */
/*   Updated: 2020/03/08 15:43:42 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	rm_mult(char *text, int i, int *n)
{
	rm(text, i);
	*n *= -1;
}

void	quote_cut_second(t_lst *tmp, t_quote *q, char **env, char *env_tmp)
{
	if (q->b == -1 && q->s == -1 && tmp->text[q->i] == '$'
		&& tmp->text[q->i + 1] != '?')
	{
		rm(tmp->text, q->i);
		env_tmp = cut_env(tmp->text, q->i);
		put_in(search_env(env_tmp, env), tmp, q->i);
	}
	else if (q->b == -1 && q->s == -1 && tmp->text[q->i] == '$'
		&& tmp->text[q->i + 1] == '?')
	{
		rm(tmp->text, q->i);
		rm(tmp->text, q->i);
		put_in(ft_itoa(q->exit_status), tmp, q->i);
	}
	if (q->b == 1)
		q->b = -1;
	(q->i)++;
}

void	quote_while(t_lst *tmp, t_quote *q, char **env, char *env_tmp)
{
	while (tmp->text[q->i])
	{
		if (q->b == -1 && q->s == -1 && tmp->text[q->i] == '\\')
		{
			rm_mult(tmp->text, q->i, &(q->b));
			continue ;
		}
		if ((q->b == -1 || q->s == 1) && tmp->text[q->i] == '\'')
		{
			rm_mult(tmp->text, q->i, &(q->s));
			continue ;
		}
		if (q->b == -1 && q->s == -1 && tmp->text[q->i] == '\"')
		{
			rm_mult(tmp->text, q->i, &(q->d));
			continue ;
		}
		quote_cut_second(tmp, q, env, env_tmp);
	}
}

void	quote_cut(t_lst **cmd, char *env[], int *exit_status)
{
	t_lst	*tmp;
	t_quote	q;
	char	env_tmp;

	tmp = *cmd;
	while (tmp)
	{
		quote_init(&q, exit_status[0]);
		quote_while(tmp, &q, env, &env_tmp);
		tmp = tmp->next;
	}
}

void	quote_search(t_args **cmd, char *env[], int *exit_status)
{
	t_args	*tmp;

	tmp = *cmd;
	while (tmp)
	{
		if (!ft_strcmp(tmp->lst->text, "echo") && tmp->lst->next
			&& !ft_strcmp(tmp->lst->next->text, "-n"))
			exit_status[1] = -1;
		if (!ft_strcmp(tmp->lst->text, "echo")
			|| !ft_strcmp(tmp->lst->text, "cd")
				|| !ft_strcmp(tmp->lst->text, "export")
					|| !ft_strcmp(tmp->lst->text, "unset")
				|| !ft_strcmp(tmp->lst->text, "exit"))
			quote_cut(&(tmp->lst->next), env, exit_status);
		tmp = tmp->next;
	}
}
