/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:21:02 by yvanat            #+#    #+#             */
/*   Updated: 2019/12/09 19:22:35 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fill_scene(t_data *data)
{
	t_list	*tmp;

	//tmp = data->plane;
	//while ((tmp = tmp->next))
	//	fill_plane(data, tmp);
	tmp = data->sphere;
	while ((tmp = tmp->next))
		fill_sphere(data, tmp);
	//tmp = data->square;
	//while ((tmp = tmp->next))
	//	fill_square(data, tmp);
	//tmp = data->cylinder;
	//while ((tmp = tmp->next))
	//	fill_cylinder(data, tmp);
	//tmp = data->triangle;
	//while ((tmp = tmp->next))
	//	fill_triangle(data, tmp);
}

void	fill_plane(t_data *data, t_list *tmp)
{
	int	x;
	int	y;
	int	z;

	x = 0;
	while (x != -1 && (int)round(x * tmp->xx) < data->x && (int)round(++x * tmp->xx) >= 0)
	{
		y = 0;
		while (y != -1 && (int)round(y * tmp->yy) < data->y && (int)round(++y * tmp->yy) >= 0)
		{
			z = 0;
			while (z != -1 && (int)round(z * tmp->zz) < data->z && (int)round(++z * tmp->zz) >= 0)
			{
				(data->scene)[(int)round(x * tmp->xx) + (int)round(y * tmp->yy)
					* data->x + (int)round(z * tmp->zz) * data->x * data->y]
					= tmp->r * 65536 + tmp->g * 256 + tmp->b;
				z++;
				if (tmp->zz == 0)
					z = -1;
			}
			y++;
			if (tmp->yy == 0)
				y = -1;
		}
		x++;
		if (tmp->xx == 0)
			x = -1;
	}
}

void	fill_sphere(t_data *data, t_list *tmp)
{
	int	x;
	int	y;
	int	z;

	x = -(int)round(tmp->xx / 2);
	while ((int)round(tmp->x + x) < data->x && (int)round(tmp->x + x) >= 0 && x <= (int)round(tmp->xx / 2))
	{
		y = -(int)round(tmp->xx / 2);
		while ((int)round(tmp->y + y) < data->y && (int)round(tmp->y + y) >= 0 && y <= (int)round(tmp->xx / 2))
		{
			z = -(int)round(tmp->xx / 2);
			while ((int)round(tmp->z + z) < data->z && (int)round(tmp->z + z) >= 0 && z <= (int)round(tmp->xx / 2))
			{
				if ((int)round(sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2))) <= (int)round(tmp->xx / 2))
				{
					(data->scene)[(int)round(tmp->x + x) + (int)round(tmp->y + y) * data->x +
						(int)round(tmp->z + z) * data->x * data->y] = tmp->r * 65536 + tmp->g * 256 + tmp->b;
				}
				z++;
			}
			y++;
		}
		x++;
	}
}

void	fill_square(t_data *data, t_list *tmp)
{
	int	x;
	int	y;
	int	z;

	x = 0;
	while (x != -1 && (int)round(tmp->x + x * tmp->xx) < data->x && (int)round(tmp->x + x * tmp->xx) >= 0 && round(x * tmp->xx) <= tmp->xxx)
	{
		y = 0;
		while (y != -1 && (int)round(tmp->y + y * tmp->yy) < data->y && (int)round(tmp->y + y * tmp->yy) >= 0 && round(x * tmp->yy) <= tmp->xxx)
		{
			z = 0;
			while (z != -1 && (int)round(tmp->z + z * tmp->zz) < data->z && (int)round(tmp->z + z * tmp->zz) >= 0 && round(z * tmp->zz) <= tmp->xxx)
			{
				(data->scene)[(int)round(tmp->x + x * tmp->xx) + (int)round(tmp->y + y * tmp->yy)
					* data->x + (int)round(tmp->z + z * tmp->zz) * data->x * data->y] = tmp->r
					* 65536 + tmp->g *256 + tmp->b;
				z++;
				if (tmp->zz == 0)
					z = -1;
			}
			y++;
			if (tmp->yy == 0)
				y = -1;
		}
		x++;
		if (tmp->xx == 0)
			x = -1;
	}
}

void	fill_cylinder(t_data *data, t_list *tmp)
{
	return ;
}
