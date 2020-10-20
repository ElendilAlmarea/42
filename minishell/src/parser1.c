/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 05:28:05 by yvanat            #+#    #+#             */
/*   Updated: 2020/03/08 14:55:34 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	prev_stop(t_args **cmd)
{
	t_args	*tmp;
	int		stock;

	stock = -1;
	tmp = *cmd;
	while (tmp)
	{
		if (stock != -1)
			tmp->pre_stop = stock;
		if (tmp->next_stop != -1)
			stock = tmp->next_stop;
		tmp = tmp->next;
	}
}

int		add_text_sixth(char *line, int *index, t_args *args, int *opt)
{
	if (line[*index] == '<' && line[*index + 1] == '<')
		args->next_stop = LESS_LESS;
	else if (line[*index] == '&' && line[*index + 1] == '&')
		args->next_stop = AND_AND;
	else if (line[*index] == '|' && line[*index + 1] == '|')
		args->next_stop = OR_OR;
	else if (line[*index + 1] == '<' || line[*index + 1] == '|' ||
			((line[*index] == '>' && line[*index + 1] == '>') &&
				(line[*index + 2] == ';' || line[*index + 2] == '<' ||
				line[*index + 2] == '|' || line[*index + 2] == '>')))
	{
		ft_dprintf(2, "bad entry\n");
		*index = -1;
		args->pre_stop = -2;
		return (1);
	}
	else
	{
		*opt = 0;
		return (0);
	}
	return (0);
}

void	add_text_seventh(char *line, int *opt, int *index, t_args *args)
{
	*opt = 1;
	if (line[*index] == ';')
		args->next_stop = SEMI_COLON;
	else if (line[*index] == '|')
		args->next_stop = PIPE;
	else if (line[*index] == '>' && line[*index + 1] == '>')
		args->next_stop = MORE_MORE;
	else if (line[*index] == '>')
		args->next_stop = MORE;
	else if (line[*index] == '<')
		args->next_stop = LESS;
	while (is_normal(line[*index], opt))
		(*index)++;
	space(line, index);
	if (line[*index] == '\0')
		*index = -1;
}

t_lst	*add_text_while(char *line, int *opt, t_lst *first, int *index)
{
	t_lst	*new;

	while (!(*opt) && *index != -1)
	{
		new = add_text_fourth(line, opt, first, index);
		add_text_fifth(line, opt, new, index);
		if (line[*index] == '\0')
			*index = -1;
		else if (line[*index] == ';' || line[*index] == '<' || line[*index]
			== '>' || line[*index] == '|' || line[*index] == '&')
			*opt = 1;
	}
	return (new);
}

void	add_text(t_args *args, char *line, int *index)
{
	int		opt;
	t_lst	*first;
	t_lst	*new;

	first = lstnew();
	opt = 0;
	if (add_text_first(line, index, first, args))
		return ;
	add_text_second(line, &opt, first, index);
	add_text_third(line, &opt, first, index);
	if (line[*index] == '\0')
		*index = -1;
	else if (line[*index] == ';' || line[*index] == '<' || line[*index] == '>'
			|| line[*index] == '|' || line[*index] == '&')
		opt = 1;
	args->lst = first;
	new = add_text_while(line, &opt, first, index);
	if (opt == 1)
	{
		if (add_text_sixth(line, index, args, &opt))
			return ;
		if (opt == 0)
			add_text_seventh(line, &opt, index, args);
	}
}
