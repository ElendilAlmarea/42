/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:21:02 by yvanat            #+#    #+#             */
/*   Updated: 2019/12/06 20:04:54 by yvanat           ###   ########.fr       */
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
	while ((int)round(++x * tmp->xx) <= data->x && (int)round(++x * tmp->xx) >= 0)
	{
		y = -1;
		while ((int)round(++y * tmp->yy) <= data->y && (int)round(++y * tmp->yy) >= 0)
		{
			z = -1;
			while ((int)round(++z * tmp->zz) <= data->z && (int)round(++z * tmp->zz) >= 0)
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
	int	x;
	int	y;
	int	z;

	x = -(int)round(tmp->xx);
	while ((int)round(tmp->x + x) <= data->x && (int)round(tmp->x + x) >= 0 && x <= (int)round(tmp->xx))
	{
		y = -(int)round(tmp->xx);
		while ((int)round(tmp->y + y) <= data->y && (int)round(tmp->y + y) >= 0 && y <= (int)round(tmp->xx))
		{
			z = -(int)round(tmp->xx);
			while ((int)round(tmp->z + z) <= data->z && (int)round(tmp->z + z) >= 0 && z <= (int)round(tmp->xx))
			{
				if ((int)round(sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))) <= (int)round(tmp->xx))
					(data->scene)[(int)round(tmp->x + x) + (int)round(tmp->y + y) * data->x +
						(int)round(tmp->z + z) * data->x * data->y] = tmp->r * 65536 + tmp->g * 256 + tmp->b;
				z++;
			}
			y++;
		}
		x++;
	}
}
void	fill_triangle(t_data *data, t_list *tmp)
{
	
}
void	fill_square(t_data *data, t_list *tmp)
{
	int	x;
	int	y;
	int	z;

	x = 0;
	while ((int)round(tmp->x + x * tmp->xx) <= data->x && (int)round(tmp->x + x * tmp->xx) >= 0 && round(x * tmp->xx) <= tmp->xxx)
	{
		y = 0;
		while ((int)round(tmp->y + y * tmp->yy) <= data->y && (int)round(tmp->y + y * tmp->yy) >= 0 && round(x * tmp->yy) <= tmp->xxx)
		{
			z = 0;
			while ((int)round(tmp->z + z * tmp->zz) <= data->z && (int)round(tmp->z + z * tmp->zz) >= 0 && round(z * tmp->zz) <= tmp->xxx)
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
