/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 14:46:34 by yvanat            #+#    #+#             */
/*   Updated: 2020/03/08 13:40:13 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	space(char *line, int *index)
{
	while (line[*index] == ' ')
		(*index)++;
}

int		is_normal(char c, int *opt)
{
	if (c == '\0' || c == ' ')
		return (0);
	if (((c == ';' || c == '<' || c == '>' || c == '|'
		|| c == '&') && !(*opt % 2)) || ((c != ';' && c != '<' && c != '>'
		&& c != '|' && c != '&') && (*opt % 2)))
		return (0);
	return (1);
}

t_args	*parse(char *line)
{
	t_args	*cmd;
	t_args	*new;
	int		index;

	index = 0;
	cmd = argsnew();
	cmd->next_stop = -1;
	cmd->pre_stop = -1;
	add_text(cmd, line, &index);
	while (index != -1)
	{
		new = argsnew();
		new->next_stop = -1;
		new->pre_stop = -1;
		add_text(new, line, &index);
		if (new->pre_stop == -2)
			cmd->pre_stop = -2;
		argsadd(&cmd, new);
	}
	prev_stop(&cmd);
	return (cmd);
}

char	*gnl(char *tmp, char *new_line, int k)
{
	char	*line;

	while (ft_get_next_line(0, &line) == 0)
	{
		if (k == 0 && line[0] == 0)
		{
			ft_printf("\n%sBye%s\n", GREEN, NONE);
			exit(0);
		}
		else
		{
			k = 1;
			tmp = new_line;
			new_line = ft_strjoin(new_line, line);
			free(tmp);
			free(line);
		}
	}
	if (k == 1)
	{
		free(line);
		line = new_line;
	}
	return (line);
}

void	gnl_call(t_args **cmd, char *env[], int *exit_status)
{
	char	*line;
	char	tmp;
	char	*new_line;
	int		k;

	new_line = ft_strdup("\0");
	k = 0;
	line = gnl(&tmp, new_line, k);
	if (line)
	{
		*cmd = parse(line);
		free(line);
		quote_search(cmd, env, exit_status);
	}
	else
		gnl_call(cmd, env, exit_status);
}
