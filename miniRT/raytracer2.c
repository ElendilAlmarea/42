/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:21:02 by yvanat            #+#    #+#             */
/*   Updated: 2019/11/18 13:34:36 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fill_scene(t_data *data)
{
	t_list	*tmp;

	while ((tmp = data->plane))
	{
		fill_plane(data, tmp);
		tmp = tmp->next;
	}
	while ((tmp = data->sphere))
	{
		fill_sphere(data, tmp);
		tmp = tmp->next;
	}
	while ((tmp = data->square))
	{
		fill_square(data, tmp);
		tmp = tmp->next;
	}
	while ((tmp = data->cylinder))
	{
		fill_cylinder(data, tmp);
		tmp = tmp->next;
	}
	while ((tmp = data->triangle))
	{
		fill_triangle(data, tmp);
		tmp = tmp->next;
	}
}

void	fill_plane(t_data *data, t_list *tmp)
{
	int	x;
	int	y;
	int	z;

	x = -1;
	while ((int)round(++x * tmp->xx) <= data->x)
	{
		y = -1;
		while ((int)round(++y * tmp->yy) <= data->y)
		{
			z = -1;
			while ((int)round(++z * tmp->zz) <= data->z)
			{
				(data->scene)[(int)round(x * tmp->xx) + (int)round(y * tmp->yy)
					* data->x + (int)round(z * tmp->zz) * data->x * data->y]
					= tmp->r * 65536 + tmp->g * 256 + tmp->b;
			}
		}
	}
}

void	fill_sphere(t_data *data, t_list *tmp)
{

}

void	fill_square(t_data *data, t_list *tmp)
{
	int	x;
	int	y;
	int	z;

	x = 0;
	while ((int)round(tmp->x + x * tmp->xx) <= data->x && round(x * tmp->xx) <= tmp->xxx)
	{
		y = 0;
		while ((int)round(tmp->y + y * tmp->yy) <= data->y && round(x * tmp->yy) <= tmp->xxx)
		{
			z = 0;
			while ((int)round(tmp->z + z * tmp->zz) <= data->z && round(z * tmp->zz) <= tmp->xxx)
			{
				(data->scene)[(int)round(tmp->x + x * tmp->xx) + (int)round(tmp->y + y * tmp->yy)
					* data->x + (int)round(tmp->z + z * tmp->zz) * data->x * data->y] = tmp->r
					* 65536 + tmp->g *256 + tmp->b;
				z++;
			}
			y++;
		}
		x++;
	}
}

void	fill_cylinder(t_data *data, t_list *tmp)
{

}
