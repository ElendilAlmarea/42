/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 02:29:16 by mbrunel           #+#    #+#             */
/*   Updated: 2020/03/10 22:33:51 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*parse_path(char *path, int indice)
{
	int		i;
	int		stop;
	int		prev;
	int		node;
	char	*dir;

	i = -1;
	node = 0;
	stop = 0;
	while (!stop)
	{
		prev = ++i;
		while (path[++i] != ':' && path[i])
			;
		if (!path[i])
			break ;
		if (node++ != indice)
			continue ;
		if ((dir = malloc(sizeof(char) * (i - prev))))
			ft_strncpy(dir, path + prev, i - prev);
		dir[i - prev] = '\0';
		return (dir);
	}
	return (NULL);
}

static char		*chr_dir(char *name, char *dir_name)
{
	struct dirent	*node;
	DIR				*dir;
	char			*path;
	char			*tmp;

	if (!dir_name || !name || !ft_strcmp(name, "\0"))
		return (NULL);
	if (!(dir = opendir(dir_name)))
		return (NULL);
	while ((node = readdir(dir)))
		if (!ft_strcmp(node->d_name, name))
		{
			closedir(dir);
			tmp = name;
			name = ft_strjoin("/", name);
			free(tmp);
			path = ft_strjoin(dir_name, name);
			free(name);
			free(dir_name);
			return (path);
		}
	closedir(dir);
	return (NULL);
}

char			*prog_path(char *name, char *env[])
{
	int		i;
	char	*path;
	char	*var;
	char	*dir;

	i = 0;
	var = search_env("PATH", env);
	while ((dir = parse_path(var, i++)))
	{
		if ((path = chr_dir(name, dir)))
			break ;
		free(dir);
	}
	if (!*name)
		name = NULL;
	return (path ? path : name);
}
