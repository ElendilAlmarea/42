/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_calls1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:11:56 by yvanat            #+#    #+#             */
/*   Updated: 2019/12/08 20:23:01 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_r(t_data *data, char *buffer, int i)
{
	while (white_space(buffer[++i]));
	data->rx = buffer[i] - 48;
	while (ft_isdigit(buffer[++i]))
		data->rx = data->rx * 10 + buffer[i] - 48;
	while (white_space(buffer[++i]));
	data->ry = buffer[i] - 48;
	while (ft_isdigit(buffer[++i]))
		data->ry = data->ry * 10 + buffer[i] - 48;
	while (white_space(buffer[++i]));
	return (i);
}

int	parse_a(t_data *data, char *buffer, int i)
{
	double	j;

	while (white_space(buffer[++i]));
	data->al = buffer[i] - 48;
	while (ft_isdigit(buffer[++i]))
		data->al = data->al * 10 + buffer[i] - 48;
	j = 0.1;
	if (buffer[i] == '.')
		while (ft_isdigit(buffer[++i]))
		{
			data->al += (buffer[i] - 48) * j;
			j /= 10;
		}
	while (white_space(buffer[++i]));
	data->ar = buffer[i] - 48;
	while (ft_isdigit(buffer[++i]))
		data->ar = data->ar * 10 + buffer[i] - 48;
	data->ag = buffer[++i] - 48;
	while (ft_isdigit(buffer[++i]))
		data->ag = data->ag * 10 + buffer[i] - 48;
	data->ab = buffer[++i] - 48;
	while (ft_isdigit(buffer[++i]))
		data->ab = data->ab * 10 + buffer[i] - 48;
	while (white_space(buffer[++i]));
	return (i);
}

int	parse_c(t_data *data, char *buffer, int i)
{
	t_list	*tmp;

	tmp = data->camera;
	while (tmp->next)
		tmp = tmp->next;
	if (!(tmp->next = malloc(sizeof(t_list))))
	{
		free(buffer);
		ft_free(data);
	}
	tmp->next->next = NULL;
	i = parse_xyz(data, buffer, i, tmp);
	i = parse_xxyyzz(data, buffer, i, tmp);
	return (i);
}

int	parse_l(t_data *data, char *buffer, int i)
{
	t_list *tmp;
	double	j;

	tmp = data->light;
	while (tmp->next)
		tmp = tmp->next;
	if (!(tmp->next = malloc(sizeof(t_list))))
	{
		free(buffer);
		ft_free(data);
	}
	tmp->next->next = NULL;
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
