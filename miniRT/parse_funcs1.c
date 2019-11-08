/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_funcs1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 18:32:51 by yvanat            #+#    #+#             */
/*   Updated: 2019/11/08 19:26:45 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	white_space(char c)
{
	return (!(c != ' ' && c != 'f' && c != 'n' && c != 'r'
		&& c != 't' && c != 'v'));
}

int	parse_rgb(t_data *data, char *buffer, int i, t_list *tmp)
{
	while (white_space(buffer[++i]));
	tmp->next->ar = buffer[i] - 48;
	while (ft_isdigit(buffer[++i]))
		tmp->next->ar = tmp->next->ar * 10 + buffer[i] - 48;
	tmp->next->ag = buffer[++i] - 48;
	while (ft_isdigit(buffer[++i]))
		tmp->next->ag = tmp->next->ag * 10 + buffer[i] - 48;
	tmp->next->ab = buffer[++i] - 48;
	while (ft_isdigit(buffer[++i]))
		tmp->next->ab = tmp->next->ab * 10 + buffer[i] - 48;
	while (white_space(buffer[++i]));
	return (i);
}

int	parse_xyz(t_data *data, char *buffer, int i, t_list *tmp)
{
	char	neg;
	double	j;

	neg = 0;
	while (white_space(buffer[++i]));
	if (buffer[i] == '-')
		neg = buffer[i++];
	tmp->next->x = buffer[i] - 48;
	while (ft_isdigit(buffer[++i]))
		tmp->next->x = tmp->next->x * 10 + buffer[i] - 48;
	j = 0.1;
	if (buffer[i] == '.')
		while (ft_isdigit(buffer[++i]))
		{
			tmp->next->x += (buffer[i] - 48) * j;
			j /= 10;
		}
	if (neg++ == '-')
		tmp->next->x *= -1;
	i = parse_y(data, buffer, i, tmp);
	return (parse_z(data, buffer, i, tmp));
}

int	parse_y(t_data *data, char *buffer, int i, t_list *tmp)
{
	char	neg;
	double	j;

	neg = 0;
	if (buffer[++i] == '-')
		neg = buffer[i++];
	tmp->next->y = buffer[i] - 48;
	while (ft_isdigit(buffer[++i]))
		tmp->next->y = tmp->next->y * 10 + buffer[i] - 48;
	j = 0.1;
	if (buffer[i] == '.')
		while (ft_isdigit(buffer[++i]))
		{
			tmp->next->y += (buffer[i] - 48) * j;
			j /= 10;
		}
	if (neg++ == '-')
		tmp->next->y *= -1;
	return (i);
}

int	parse_z(t_data *data, char *buffer, int i, t_list *tmp)
{
	char	neg;
	double	j;

	neg = 0;
	if (buffer[++i] == '-')
		neg = buffer[i++];
	tmp->next->z = buffer[i] - 48;
	while (ft_isdigit(buffer[++i]))
		tmp->next->z = tmp->next->z * 10 + buffer[i] - 48;
	j = 0.1;
	if (buffer[i] == '.')
		while (ft_isdigit(buffer[++i]))
		{
			tmp->next->z += (buffer[i] - 48) * j;
			j /= 10;
		}
	if (neg++ == '-')
		tmp->next->z *= -1;
	while (white_space(buffer[++i]));
	return (i);
}
