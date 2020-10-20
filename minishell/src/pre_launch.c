/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_launch.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:29:20 by mbrunel           #+#    #+#             */
/*   Updated: 2020/03/08 03:06:47 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int		check_builtin(char *name)
{
	char	**tab;
	int		i;

	i = -1;
	tab = (char*[]){"zero", "echo", "cd",
		"pwd", "export", "unset", "env", "exit", NULL};
	while (tab[++i])
		if (!ft_strcmp(tab[i], name))
			return (i);
	return (0);
}

static void		conc_lst(t_lst *act, t_lst *file)
{
	t_lst *node;

	if (!file)
		return ;
	free(file->text);
	node = act;
	if (!node)
	{
		free(file);
		return ;
	}
	while (node->next)
		node = node->next;
	node->next = file->next;
	free(file);
}

static void		link_fd(t_args *arg)
{
	int		p[2];

	pipe(p);
	arg->out = p[1];
	arg->next->in = p[0];
}

static void		set_up_fd(t_args *arg, char *env[])
{
	t_args	*tmp;
	int		var;

	if (!arg->next || arg->next_stop < PIPE)
		return ;
	if (arg->next_stop == PIPE)
	{
		link_fd(arg);
		return ;
	}
	if (arg->next_stop == MORE)
		var = O_WRONLY | O_CREAT | O_TRUNC;
	else if (arg->next_stop == MORE_MORE)
		var = O_WRONLY | O_CREAT | O_APPEND;
	else if (arg->next_stop == LESS)
		arg->in = open(arg->next->lst->text, O_RDONLY);
	if (arg->next_stop != LESS)
		arg->out = open(arg->next->lst->text, var, 00644);
	tmp = arg->next;
	conc_lst(arg->lst, arg->next->lst);
	arg->next = arg->next->next;
	arg->next_stop = tmp->next_stop;
	free(tmp);
	if (arg->next_stop > PIPE)
		set_up_fd(arg, env);
}

void			launch_stuff(t_args *cmd, char *av[], char **env[],
														int *exit_status)
{
	t_args		*node;
	int			save[2];
	int			status;
	int			builtin;

	node = cmd;
	while (node)
	{
		node->in = node->in == -1 ? 0 : node->in;
		node->out = node->out == -1 ? 1 : node->out;
		if (!(builtin = check_builtin(node->lst->text)))
			node->lst->text = prog_path(node->lst->text, *env);
		save_std(save, save + 1);
		set_up_fd(node, *env);
		set_std(node);
		if (builtin)
			status = launch_builtin(builtin, node, env);
		else if (node->lst->text)
			status = launch_one(node, av, *env, exit_status);
		reset_std(save[0], save[1]);
		if ((status && node->next_stop == AND_AND) ||
			(!status && node->next_stop == OR_OR))
			break ;
		node = node->next;
	}
}
