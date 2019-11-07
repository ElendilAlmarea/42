/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_calls1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:11:56 by yvanat            #+#    #+#             */
/*   Updated: 2019/11/07 20:46:22 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	parse_r(t_data *data, char *buffer, int i)
{
	while (!white_space(buffer[++i]));
	data->rx = buffer[i];
	while (!white_space(buffer[++i]));
	data->ry = buffer[i];
	while (!white_space(buffer[++i]));
	return (i);
}

int	parse_a(t_data *data, char *buffer, int i)
{
	while (!white_space(buffer[++i]));
	data->al = buffer[i];
	while (!white_space(buffer[++i]));
	data->ar = buffer[i];
	while (!white_space(buffer[++i]));
	data->ag = buffer[i];
	while (!white_space(buffer[++i]));
	data->ab = buffer[i];
	while (!white_space(buffer[++i]));
	return (i);
}

int	parse_c(t_data *data, char *buffer, int i)
{

}

int	parse_l(t_data *data, char *buffer, int i)
{

}

int	parse_pl(t_data *data, char *buffer, int i)
{

}
