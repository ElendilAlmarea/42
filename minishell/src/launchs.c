/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launchs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 02:59:41 by mbrunel           #+#    #+#             */
/*   Updated: 2020/03/08 03:01:17 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		launch_one(t_args *arg, char *av[], char *env[], int *exit_st)
{
	int		i;
	t_lst	*node;
	int		status;

	node = arg->lst;
	i = -1;
	while (node)
	{
		av[++i] = node->text;
		node = node->next;
	}
	av[i + 1] = NULL;
	if (!(g_pid = fork()))
	{
		execve(av[0], av, env);
		ft_dprintf(2, "%s%s:%s %s: %s%s\n", C_ERROR, SHELL,
			NONE, "command not found", NONE, av[0]);
		exit(-1);
	}
	wait(&status);
	exit_st[0] = WEXITSTATUS(status);
	return (status);
}

int		launch_builtin(int builtin, t_args *arg, char **env[])
{
	char *current_d;

	g_pid = -1;
	if (builtin == CD && cd(arg->lst->next, env) == -1)
		return (-1);
	if (builtin == PWD && !(current_d = pwd()))
		return (-1);
	if (builtin == PWD && !aff_pwd())
		return (-1);
	if (builtin == EXPORT && !(*env = export(*env, arg->lst->next, '+')))
		return (-1);
	if (builtin == UNSET && !(*env = export(*env, arg->lst->next, '-')))
		return (-1);
	if (builtin == ECHO)
		echo(arg->lst->next);
	else if (builtin == ENV)
		aff_env(*env);
	else if (builtin == EXIT)
		bye(0);
	return (0);
}
