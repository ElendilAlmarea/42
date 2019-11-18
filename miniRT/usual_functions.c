/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usual_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:48:02 by yvanat            #+#    #+#             */
/*   Updated: 2019/11/18 13:08:52 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int		ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

void	data_init(t_list *data)
{
	data->camera = NULL;
	data->light = NULL;
	data->plane = NULL;
	data->sphere = NULL;
	data->square = NULL;
	data->cylinder= NULL;
	data->triangle = NULL;
}
