/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directories.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 03:29:18 by mbrunel           #+#    #+#             */
/*   Updated: 2020/03/08 13:26:08 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*set_path(char *env[], t_lst *arg)
{
	char *path;

	if (!arg)
		path = search_env("HOME", env);
	else if (arg->text[0] == '-')
	{
		path = search_env("OLDPWD", env);
		ft_printf("%s\n", path);
	}
	else
		path = arg->text;
	return (path);
}

int			cd(t_lst *arg, char **env[])
{
	char	*path;
	t_lst	exp;
	t_lst	next;
	char	*dirs[2];
	char	*tmp;

	tmp = pwd();
	if (!(dirs[0] = ft_strjoin("OLDPWD=", tmp)))
		return (-1);
	free(tmp);
	if ((path = set_path(*env, arg)) && chdir(path))
	{
		ft_dprintf(2, "%s%s:%s %s: %s%s\n", C_ERROR, SHELL,
			NONE, strerror(errno), NONE, path);
		return (-1);
	}
	tmp = pwd();
	if (!(dirs[1] = ft_strjoin("PWD=", tmp)))
		return (-1);
	free(tmp);
	next = (t_lst){dirs[1], NULL};
	exp = (t_lst){dirs[0], &next};
	if (!(*env = export(*env, &exp, '+')))
		return (-1);
	return (0);
}

char		*pwd(void)
{
	char	*buf;
	int		st;

	st = 1;
	while (1)
	{
		if (!(buf = malloc(BUFFER_SIZE * st * sizeof(char))))
			return (NULL);
		if ((getcwd(buf, BUFFER_SIZE * st)))
			break ;
		free(buf);
		st += 1;
		if (errno == ERANGE)
			continue ;
		ft_dprintf(2, "%s%s:%s %s: %s%s\n", C_ERROR, SHELL,
			NONE, strerror(errno), NONE, "pwd");
		return (NULL);
	}
	return (buf);
}
