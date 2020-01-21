/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 19:31:59 by yvanat            #+#    #+#             */
/*   Updated: 2019/12/09 20:14:27 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fill_triangle(t_data *data, t_list *tmp)
{
	return ;
}

void	raytracing(t_data *data)
{
	int		rx;
	int		ry;
	int		i;
	int		j;
	double	x;
	double	y;
	double	z;
	double	ix;
	double	iy;
	double	iz;
	double	step;
	t_list	*tmp;
	int		*render;
	tmp = data->camera->next;
	if (tmp->xx == 0 && tmp->yy == 0 && tmp->zz == 0)
		return ;
	if (!(render = malloc(sizeof(int) * data->rx * data->ry)))
		ft_free(data);
	j = 0;
	while (j < 100000 && ((tmp->x + j * tmp->xx >= data->x || tmp->x + j * tmp->xx < 0) || (tmp->y + j * tmp->yy >= data->y || tmp->y + j * tmp->yy < 0) || (tmp->z + j * tmp->zz > data->z || tmp->z + j * tmp->zz < 0)))
		j++;
	if (j == 100000)
		return ;
	rx = 0;
	ry = 0;
	while (rx < data->rx)
	{
		while (ry < data->ry)
		{
			render[rx + ry * data->rx] = 0;
			x = tmp->xx;
			y = tmp->yy + 2 * rx / j;
			z = tmp->zz + 2 * ry / j;
			step = x > y ? x : y;
			step = step > z ? 1 / step : 1 / z;
			i = 0;
			while (i < 100000 && ((tmp->x + i * step * x >= data->x || tmp->x + i * step * x < 0) || (tmp->y + i * step * y >= data->y || tmp->y + i * step * y < 0) || (tmp->z + i * step * z >= data->z || tmp->z + i * step * z < 0)))
				i++;
			while (tmp->x + i * step * x < data->x && tmp->y + i * step * y < data->y && tmp->z + i * step * z <= data->z && tmp->x + i * step * x >= 0 && tmp->y + i * step * y >= 0 && tmp->z + i * step * z >= 0)
			{
				if ((data->scene)[(int)round(tmp->x + i * step * x) + (int)round(tmp->y + i * step * y) * data->x + (int)round(tmp->z + i * step * z) * data->x * data->y] != 0)
				{
					render[rx + ry * data->rx] = (data->scene)[(int)round(tmp->x + i * step * x) + (int)round(tmp->y + i * step * y) * data->x + (int)round(tmp->z + i * step * z) * data->x * data->y];
					ix = tmp->x + i * step * x;
					iy = tmp->y + i * step * y;
					iz = tmp->z + i * step * z;
					x = data->light->x - ix;
					y = data->light->y - iy;
					z = data->light->z - iz;
					step = x > y ? x : y;
					step = step > z ? 1 / step : 1 / z;
					i = 0;
					while (ix + i * step * x < data->x && iy + i * step * y < data->y && iz + i * step * z <= data->z && ix + i * step * x >= 0 && iy + i * step * y >= 0 && iz + i * step * z >= 0)
					{
						if ((data->scene)[(int)round(ix + i * step * x) + (int)round(iy + i * step * y) * data->x + (int)round(iz + i * step * z) * data->x * data->y] != 0)
							render[rx + ry * data->rx] = 100 * 65536 + 100 * 256 + 100;
						i++;
					}
				}
				i++;
			}
			ry++;
		}
		rx++;
	}
	i = 0;
	while (i < data->rx)
	{
		j = 0;
		while (j < data->ry)
		{
			if (render[i + j * data->rx])
				mlx_pixel_put(data->mlx_ptr, data->win_ptr, i, j, render[i + j * data->rx]);
			j++;
		}
		i++;
	}
}