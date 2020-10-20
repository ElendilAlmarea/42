/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 14:45:08 by yvanat            #+#    #+#             */
/*   Updated: 2020/03/08 15:50:16 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	rm(char *text, int i)
{
	while (text[++i])
		text[i - 1] = text[i];
	text[i - 1] = '\0';
}

char	*cut_env(char *text, int i)
{
	int		j;
	int		opt;
	char	*env;

	opt = 0;
	j = 0;
	while (text[i + j] != '/' && is_normal(text[i + j], &opt) &&
		text[i + j] != '\"' && text[i + j] != '\'')
		j++;
	if (!(env = malloc(j + 1)))
		exit(0);
	j = 0;
	while (text[i + j] != '/' && is_normal(text[i + j], &opt) &&
		text[i + j] != '\"' && text[i + j] != '\'')
	{
		env[j] = text[i + j];
		j++;
	}
	env[j] = '\0';
	j = -1;
	while (++j < (int)ft_strlen(env))
		rm(text, i);
	return (env);
}

char	*search_env(char *env_tmp, char *env[])
{
	int	i;

	i = 0;
	while (env[++i])
		if (!ft_strncmp(env[i], env_tmp, ft_strlen(env_tmp)))
			return (env[i] + ft_strlen(env_tmp) + 1);
	return ("");
}

void	put_in(char *env, t_lst *tmp, int i)
{
	char	*new_text;
	int		j;

	new_text = malloc(ft_strlen(tmp->text) + ft_strlen(env) + 1);
	j = -1;
	while (++j < i)
		new_text[j] = tmp->text[j];
	j = -1;
	while (env[++j])
		new_text[i + j] = env[j];
	while (tmp->text[i])
	{
		new_text[i + j] = tmp->text[i];
		i++;
	}
	new_text[i + j] = '\0';
	free(tmp->text);
	tmp->text = new_text;
}

void	quote_init(t_quote *q, int exit_status)
{
	q->b = -1;
	q->s = -1;
	q->d = -1;
	q->i = 0;
	q->exit_status = exit_status;
}
