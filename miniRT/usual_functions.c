/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usual_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:48:02 by yvanat            #+#    #+#             */
/*   Updated: 2019/12/08 20:21:24 by yvanat           ###   ########.fr       */
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

void	ft_free(t_data *data)
{
	return ;
}

void	data_init(t_data *data)
{
	if (!(data->camera = malloc(sizeof(t_list))))
		ft_free(data);
	data->camera->next = NULL;
	if (!(data->light = malloc(sizeof(t_list))))
		ft_free(data);
	data->light->next = NULL;
	if (!(data->plane = malloc(sizeof(t_list))))
		ft_free(data);
	data->plane->next = NULL;
	if (!(data->sphere = malloc(sizeof(t_list))))
		ft_free(data);
	data->sphere->next = NULL;
	if (!(data->square = malloc(sizeof(t_list))))
		ft_free(data);
	data->square->next = NULL;
	if (!(data->cylinder = malloc(sizeof(t_list))))
		ft_free(data);
	data->cylinder->next= NULL;
	if (!(data->triangle = malloc(sizeof(t_list))))
		ft_free(data);
	data->triangle->next = NULL;
}

void	put_error(ssize_t size)
{
	return ;
}
