/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 03:03:34 by mbrunel           #+#    #+#             */
/*   Updated: 2020/03/08 15:15:18 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	env_in_loop(char *env[], t_venv *v, int mode, char *str)
{
	if (!ft_strncmp(env[v->i], v->token, v->len_token) && !v->boo)
	{
		if (mode == '+')
			v->new_env[v->i] = ft_strdup(str);
		else if (mode == '-')
			v->todel = v->i;
		else
			v->new_env[v->i] = ft_strdup(env[v->i]);
		v->boo = 1;
	}
	else
		v->new_env[v->i] = ft_strdup(env[v->i]);
}

char		**update_env(char *env[], char *str, char mode)
{
	t_venv v;

	v.boo = 0;
	v.i = -1;
	v.todel = -1;
	while (str[++v.i] && str[v.i] != '=')
		v.token[v.i] = str[v.i];
	v.token[v.i] = '\0';
	v.len_token = v.i;
	v.i = -1;
	while (env[++v.i])
		;
	if (!(v.new_env = malloc(sizeof(char*) * (v.i + 5))))
		return (NULL);
	v.i = -1;
	while (env[++v.i])
		env_in_loop(env, &v, mode, str);
	if (!v.boo && mode == '+')
		v.new_env[v.i++] = ft_strdup(str);
	else if (v.todel >= 0)
		v.new_env[v.todel] = v.new_env[--v.i];
	v.new_env[v.i] = NULL;
	return (v.new_env);
}

char		**export(char *env[], t_lst *lst, int mode)
{
	int		i;
	char	**new_env;

	i = -2;
	if (!lst)
	{
		if (mode == '+')
			aff_env(env);
		return (env);
	}
	while (lst)
	{
		if (i != -2)
			env = new_env;
		if (!(new_env = update_env(env, lst->text, mode)))
			return (NULL);
		i = -1;
		while (env[++i])
			free(env[i]);
		free(env);
		lst = lst->next;
	}
	return (new_env);
}
