/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:20:49 by yvanat            #+#    #+#             */
/*   Updated: 2019/11/08 16:00:59 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	scene_matrix(t_data *data)
{
	int		xyz[6];
	t_data	*tmp;
	int		i;

	tmp = data->plane;
	while (tmp)
	{
		max_plane(tmp, xyz);
		tmp = tmp->next;
	}
	tmp = data->sphere;
	while (tmp)
	{
		max_sphere(tmp, xyz);
		tmp = tmp->next;
	}
	tmp = data->square;
	while (tmp)
	{
		max_square(tmp, xyz);
		tmp = tmp->next;
	}
	tmp = data->cylinder;
	while (tmp)
	{
		max_cylinder(tmp, xyz);
		tmp = tmp->next;
	}
	tmp = data->triangle;
	while (tmp)
	{
		max_triangle(tmp, xyz);
		tmp = tmp->next;
	}
	i = (xyz[0] - xyz[1] + 1) * (xyz[2] - xyz[3] + 1) * (xyz[4] - xyz[5] + 1);
	if (!(data->scene = malloc(sizeof(int) * i)))
		ft_free(data);
	while (i--)
		(data->scene)[i] = 0;
}
