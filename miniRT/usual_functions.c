/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usual_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:48:02 by yvanat            #+#    #+#             */
/*   Updated: 2019/11/06 19:47:23 by yvanat           ###   ########.fr       */
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

void	data_init(t_list *data)
{
	data->camera = malloc(sizeof(t_list));
	data->light = malloc(sizeof(t_list));
	data->plane = malloc(sizeof(t_list));
	data->sphere = malloc(sizeof(t_list));
	data->square = malloc(sizeof(t_list));
	data->cylinder= malloc(sizeof(t_list));
	data->triangle = malloc(sizeof(t_list));
	if (!data->camera || !data->light || !data->plane || !data->sphere
		|| !data->square || !data->cylinder || !data->triangle)
		ft_free(data);
	data->camera->next = NULL;
	data->light->next = NULL;
	data->plane->next = NULL;
	data->sphere->next = NULL;
	data->square->next = NULL;
	data->cylinder->next = NULL;
	data->triangle->next = NULL;
}
