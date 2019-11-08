/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_calls2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:12:17 by yvanat            #+#    #+#             */
/*   Updated: 2019/11/08 19:52:32 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_pl(t_data *data, char *buffer, int i)
{
	t_list *tmp;

	tmp = data->plane;
	while (tmp)
		tmp = tmp->next;
	if (!(tmp->next = malloc(sizeof(t_list))))
	{
		free(buffer);
		ft_free(data);
	}
	tmp->next->next = NULL;
	i++;
	i = parse_xyz(data, buffer, i, tmp);
	i = parse_xxyyzz(data, buffer, i, tmp);
	return (parse_rgb(data, buffer, i, tmp));
}

int	parse_sp(t_data *data, char *buffer, int i)
{
	t_list *tmp;
	double	j;

	tmp = data->sphere;
	while (tmp)
		tmp = tmp->next;
	if (!(tmp->next = malloc(sizeof(t_list))))
	{
		free(buffer);
		ft_free(data);
	}
	tmp->next->next = NULL;
	i++;
	i = parse_xyz(data, buffer, i, tmp);
	tmp->next->xx = buffer[i] - 48;
	while (ft_isdigit(buffer[++i]))
		tmp->next->xx = tmp->next->xx * 10 + buffer[i] - 48;
	j = 0.1;
	if (buffer[i] == '.')
		while (ft_isdigit(buffer[++i]))
		{
			tmp->next->xx += (buffer[i] - 48) * j;
			j /= 10;
		}
	return (parse_rgb(data, buffer, i, tmp));
}

int	parse_sq(t_data *data, char *buffer, int i)
{
	t_list *tmp;
	double	j;

	tmp = data->square;
	while (tmp)
		tmp = tmp->next;
	if (!(tmp->next = malloc(sizeof(t_list))))
	{
		free(buffer);
		ft_free(data);
	}
	tmp->next->next = NULL;
	i++;
	i = parse_xyz(data, buffer, i, tmp);
	i = parse_xxyyzz(data, buffer, i, tmp);
	tmp->next->xxx = buffer[i] - 48;
	while (ft_isdigit(buffer[++i]))
		tmp->next->xxx = tmp->next->xxx * 10 + buffer[i] - 48;
	j = 0.1;
	if (buffer[i] == '.')
		while (ft_isdigit(buffer[++i]))
		{
			tmp->next->xxx += (buffer[i] - 48) * j;
			j /= 10;
		}
	return (parse_rgb(data, buffer, i, tmp));
}

int	parse_cy(t_data *data, char *buffer, int i)
{
	t_list *tmp;
	double	j;

	tmp = data->cylinder;
	while (tmp)
		tmp = tmp->next;
	if (!(tmp->next = malloc(sizeof(t_list))))
	{
		free(buffer);
		ft_free(data);
	}
	tmp->next->next = NULL;
	i++;
	i = parse_xyz(data, buffer, i, tmp);
	i = parse_xxyyzz(data, buffer, i, tmp);
	tmp->next->xxx = buffer[i] - 48;
	while (ft_isdigit(buffer[++i]))
		tmp->next->xxx = tmp->next->xxx * 10 + buffer[i] - 48;
	j = 0.1;
	if (buffer[i] == '.')
		while (ft_isdigit(buffer[++i]))
		{
			tmp->next->xxx += (buffer[i] - 48) * j;
			j /= 10;
		}
	while (white_space(buffer[++i]));
	tmp->next->yyy = buffer[i] - 48;
	while (ft_isdigit(buffer[++i]))
		tmp->next->yyy = tmp->next->yyy * 10 + buffer[i] - 48;
	j = 0.1;
	if (buffer[i] == '.')
		while (ft_isdigit(buffer[++i]))
		{
			tmp->next->yyy += (buffer[i] - 48) * j;
			j /= 10;
		}
	return (parse_rgb(data, buffer, i, tmp));
}

int	parse_tr(t_data *data, char *buffer, int i)
{
	t_list *tmp;
	double	j;

	tmp = data->triangle;
	while (tmp)
		tmp = tmp->next;
	if (!(tmp->next = malloc(sizeof(t_list))))
	{
		free(buffer);
		ft_free(data);
	}
	tmp->next->next = NULL;
	i++;
	i = parse_xyz(data, buffer, i, tmp);
	i = parse_xxyyzz(data, buffer, i, tmp);
	i = parse_xxxyyyzzz(data, buffer, i, tmp);
	return (parse_rgb(data, buffer, i, tmp));
}
