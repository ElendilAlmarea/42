/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_funcs3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 19:55:56 by yvanat            #+#    #+#             */
/*   Updated: 2019/11/08 19:56:04 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_zzz(t_data *data, char *buffer, int i, t_list *tmp)
{
	char	neg;
	double	j;

	neg = 0;
	if (buffer[++i] == '-')
		neg = buffer[i++];
	tmp->next->zzz = buffer[i] - 48;
	while (ft_isdigit(buffer[++i]))
		tmp->next->zzz = tmp->next->zzz * 10 + buffer[i] - 48;
	j = 0.1;
	if (buffer[i] == '.')
		while (ft_isdigit(buffer[++i]))
		{
			tmp->next->zzz += (buffer[i] - 48) * j;
			j /= 10;
		}
	if (neg++ == '-')
		tmp->next->zzz *= -1;
	while (white_space(buffer[++i]));
	return (i);
}
