/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 01:15:31 by mbrunel           #+#    #+#             */
/*   Updated: 2020/03/08 03:46:10 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	**init_env(char *env[], char *name)
{
	char *tmp;
	char *path;
	char *shell;

	tmp = pwd();
	if (!(path = ft_strjoin(tmp, "/")))
		return (NULL);
	free(tmp);
	if (!(shell = ft_strjoin(path, name)))
		return (NULL);
	tmp = shell;
	if (!(shell = ft_strjoin("SHELL=", shell)))
		return (NULL);
	free(tmp);
	return (update_env(env, shell, '+'));
}

char	*nicer(char *location)
{
	int		i;
	char	*new;

	i = ft_strlen(location);
	while (location[--i] != '/')
		;
	new = ft_strdup(location + i + 1);
	free(location);
	return (new);
}

void	recup_signal(int sig)
{
	char *location;

	if (sig == SIGINT)
	{
		if (g_pid != -1)
		{
			kill(g_pid, SIGINT);
			ft_printf("\n");
			g_pid = -1;
		}
		else
		{
			ft_printf("\n%s%s: %s%s$ ", C_SHELL,
				SHELL, NONE, location = nicer(pwd()));
			free(location);
		}
	}
	if (sig == SIGQUIT)
		if (g_pid != -1)
		{
			kill(g_pid, SIGQUIT);
			ft_printf("[1] %d quit\n", (int)g_pid);
			g_pid = -1;
		}
}

void	launch(int *exit_status, char **av, char **env)
{
	t_args	*o;
	char	*location;

	while (1)
	{
		g_pid = -1;
		if (exit_status[1] == -1)
		{
			exit_status[1] = 0;
			ft_printf("%s%%\n", C_ERROR);
		}
		ft_printf("%s%s: %s%s$ ", C_SHELL, SHELL,
			NONE, location = nicer(pwd()));
		free(location);
		o = NULL;
		gnl_call(&o, env, exit_status);
		if (o && o->pre_stop == -2)
		{
			argsclear(o);
			continue ;
		}
		launch_stuff(o, av, &env, exit_status);
		argsclear(o);
	}
}

int		main(int ac, char *av[], char *o_env[])
{
	int		exit_status[2];
	char	**env;

	exit_status[0] = 0;
	exit_status[1] = 0;
	if (!(env = init_env(o_env, av[0])))
		bye(-1);
	if (ac != 1)
		exit(0);
	signal(SIGINT, recup_signal);
	signal(SIGQUIT, recup_signal);
	launch(exit_status, av, env);
	return (0);
}
