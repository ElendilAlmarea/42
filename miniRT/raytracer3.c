/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 19:31:59 by yvanat            #+#    #+#             */
/*   Updated: 2019/12/06 20:52:53 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fill_triangle(t_data *data, t_list *tmp)
{
	
}

void	raytracing(t_data *data)
{
	int		rx;
	int		ry;
	int		i;
	int		cx;
	int		cy;
	int		cz;
	double	x;
	double	y;
	double	z;
	double	ix;
	double	iy;
	double	iz;
	double	step;
	t_list	*tmp;
	int		*render;

	tmp = data->camera;
	if (!(render = malloc(sizeof(int) * 4 * data->rx * data->ry)))
		ft_free(data);
	i = 0;
	while (i < 100000 && ((tmp->x + i * tmp->xx > data->x || tmp->x + i * tmp->xx < 0) || (tmp->y + i * tmp->yy > data->y || tmp->y + i * tmp->yy < 0) || (tmp->z + i * tmp->zz > data->z || tmp->z + i * tmp->zz < 0)))
		i++;
	if (i == 100000)
		break ;
	cx = tmp->x + i * tmp->xx / 2;
	cy = tmp->y + i * tmp->yy / 2;
	cz = tmp->z + i * tmp->zz / 2;
	rx = 0;
	ry = 0;
	while (rx < data->rx)
	{
		while (ry < data->ry)
		{
			render[rx + ry * data->rx] = 0;
			x = render[2 * (rx + ry * data->rx)] - tmp->x;
			y = render[3 * (rx + ry * data->rx)] - tmp->y;
			z = render[4 * (rx + ry * data->rx)] - tmp->z;
			step = x > y ? x : y;
			step = step > z ? 1 / step : 1 / z;
			i = 0;
			while (i * step * x <= data->x && i * step * y <= data->y && i * step * z <= data->z && i * step * x >= 0 && i * step * y >= 0 && i * step * z >= 0)
			{
				if ((data->scene)[i * (int)round(step * x) + i * (int)round(step * y * data->x) + i * (int)round(step * z * data->x * data->y)] != 0)
				{
					render[rx + ry * data->rx] = 100 * 65536 + 100 * 256 + 100;
					ix = i * step * x;
					iy = i * step * y;
					iz = i * step * z;
					x = data->light->x - ix;
					y = data->light->y - iy;
					z = data->light->z - iz;
					step = x > y ? x : y;
					step = step > z ? 1 / step : 1 / z;
					i = 0;
					while (ix + i * step * x <= data->x && iy + i * step * y <= data->y && iz + i * step * z <= data->z && ix + i * step * x >= 0 && iy + i * step * y >= 0 && iz + i * step * z >= 0)
					{
						if ((data->scene)[(int)round(ix + i * step * x) + (int)round(iy + i * step * y) * data->x + (int)round(iz + i * step * z) * data->x * data->y] != 0)
							render[rx + ry * data->rx] = 0;
						i++;
					}
				}
				i++;
			}
			ry++;
		}
		rx++;
	}
}