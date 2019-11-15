/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:21:02 by yvanat            #+#    #+#             */
/*   Updated: 2019/11/15 21:19:20 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fill_scene(t_data *data)
{
	t_list	*tmp;

	while ((tmp = data->plane))
	{
		fill_plane(data);
		tmp = tmp->next;
	}
	while ((tmp = data->sphere))
	{
		fill_sphere(data);
		tmp = tmp->next;
	}
	while ((tmp = data->square))
	{
		fill_square(data);
		tmp = tmp->next;
	}
	while ((tmp = data->cylinder))
	{
		fill_cylinder(data);
		tmp = tmp->next;
	}
	while ((tmp = data->triangle))
	{
		fill_triangle(data);
		tmp = tmp->next;
	}
}

void	fill_plane(t_data *data)
{
	
}

void	fill_sphere(t_data *data)
{

}

void	fill_square(t_data *data)
{

}

void	fill_cylinder(t_data *data)
{

}
