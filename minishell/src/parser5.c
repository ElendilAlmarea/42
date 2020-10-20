/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 14:55:43 by yvanat            #+#    #+#             */
/*   Updated: 2020/03/08 14:56:00 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		add_text_first(char *line, int *index, t_lst *first, t_args *args)
{
	space(line, index);
	while (line[*index] == ';')
	{
		(*index)++;
		space(line, index);
	}
	if (line[*index] == '<' || line[*index] == '>' || line[*index] == '|')
	{
		ft_dprintf(2, "bad entry\n");
		first->text = malloc(1);
		args->lst = first;
		*index = -1;
		args->pre_stop = -2;
		return (1);
	}
	return (0);
}

void	add_text_second(char *line, int *opt, t_lst *first, int *index)
{
	int	k;

	k = 0;
	while (is_normal(line[*index + k], opt))
	{
		if (line[*index + k] == '\"' || line[*index + k] == '\'')
		{
			k++;
			while (line[*index + k] && line[*index + k] != '\"'
				&& line[*index + k] != '\'')
				k++;
		}
		else if (line[*index + k] == '\\')
			k++;
		k++;
	}
	first->text = malloc(k + 1);
}

void	add_text_third(char *line, int *opt, t_lst *first, int *index)
{
	int	k;

	k = 0;
	while (is_normal(line[*index], opt))
	{
		if (line[*index] == '\"' || line[*index] == '\'')
		{
			first->text[k++] = line[(*index)];
			(*index)++;
			while (line[*index] && line[*index] != '\"' && line[*index] != '\'')
			{
				first->text[k++] = line[(*index)];
				(*index)++;
			}
		}
		else if (line[*index] == '\\')
		{
			first->text[k++] = line[(*index)];
			(*index)++;
		}
		first->text[k++] = line[(*index)];
		(*index)++;
	}
	first->text[k] = '\0';
	space(line, index);
}

t_lst	*add_text_fourth(char *line, int *opt, t_lst *first, int *index)
{
	int		k;
	t_lst	*new;

	new = lstnew();
	lstadd(&first, new);
	k = 0;
	space(line, index);
	while (is_normal(line[*index + k], opt))
	{
		if (line[*index + k] == '\"' || line[*index + k] == '\'')
		{
			k++;
			while (line[*index + k] && line[*index + k] != '\"'
				&& line[*index + k] != '\'')
				k++;
		}
		else if (line[*index + k] == '\\')
			k++;
		k++;
	}
	new->text = malloc(k + 1);
	return (new);
}

void	add_text_fifth(char *line, int *opt, t_lst *new, int *index)
{
	int	k;

	k = 0;
	while (is_normal(line[*index], opt))
	{
		if (line[*index] == '\"' || line[*index] == '\'')
		{
			new->text[k++] = line[(*index)];
			(*index)++;
			while (line[*index] && line[*index] != '\"' && line[*index] != '\'')
			{
				new->text[k++] = line[(*index)];
				(*index)++;
			}
		}
		else if (line[*index] == '\\')
		{
			new->text[k++] = line[(*index)];
			(*index)++;
		}
		new->text[k++] = line[(*index)];
		(*index)++;
		new->text[k] = '\0';
	}
	space(line, index);
}
