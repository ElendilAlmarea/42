/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_funcs2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 19:26:47 by yvanat            #+#    #+#             */
/*   Updated: 2019/11/08 19:55:41 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_xxyyzz(t_data *data, char *buffer, int i, t_list *tmp)
{
	char	neg;
	double	j;

	neg = 0;
	if (buffer[i] == '-')
		neg = buffer[i++];
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
	if (neg++ == '-')
		tmp->next->xx *= -1;
	i = parse_yy(data, buffer, i, tmp);
	return (parse_zz(data, buffer, i, tmp));
}

int	parse_yy(t_data *data, char *buffer, int i, t_list *tmp)
{
	char	neg;
	double	j;

	neg = 0;
	if (buffer[++i] == '-')
		neg = buffer[i++];
	tmp->next->yy = buffer[i] - 48;
	while (ft_isdigit(buffer[++i]))
		tmp->next->yy = tmp->next->yy * 10 + buffer[i] - 48;
	j = 0.1;
	if (buffer[i] == '.')
		while (ft_isdigit(buffer[++i]))
		{
			tmp->next->yy += (buffer[i] - 48) * j;
			j /= 10;
		}
	if (neg++ == '-')
		tmp->next->yy *= -1;
	return (i);
}

int	parse_zz(t_data *data, char *buffer, int i, t_list *tmp)
{
	char	neg;
	double	j;

	neg = 0;
	if (buffer[++i] == '-')
		neg = buffer[i++];
	tmp->next->zz = buffer[i] - 48;
	while (ft_isdigit(buffer[++i]))
		tmp->next->zz = tmp->next->zz * 10 + buffer[i] - 48;
	j = 0.1;
	if (buffer[i] == '.')
		while (ft_isdigit(buffer[++i]))
		{
			tmp->next->zz += (buffer[i] - 48) * j;
			j /= 10;
		}
	if (neg++ == '-')
		tmp->next->zz *= -1;
	while (white_space(buffer[++i]));
	return (i);
}

int	parse_xxxyyyzzz(t_data *data, char *buffer, int i, t_list *tmp)
{
	char	neg;
	double	j;

	neg = 0;
	if (buffer[i] == '-')
		neg = buffer[i++];
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
	if (neg++ == '-')
		tmp->next->xxx *= -1;
	i = parse_yyy(data, buffer, i, tmp);
	return (parse_zzz(data, buffer, i, tmp));
}

int	parse_yyy(t_data *data, char *buffer, int i, t_list *tmp)
{
	char	neg;
	double	j;

	neg = 0;
	if (buffer[++i] == '-')
		neg = buffer[i++];
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
	if (neg++ == '-')
		tmp->next->yyy *= -1;
	return (i);
}
