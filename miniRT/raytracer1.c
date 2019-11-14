/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:20:49 by yvanat            #+#    #+#             */
/*   Updated: 2019/11/14 16:11:00 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	scene_matrix(t_data *data)
{
	double	xyz[6];
	int		i;

	max_sphere(data, xyz);
	max_square(data, xyz);
	max_cylinder(data, xyz);
	max_triangle(data, xyz);
	i = (xyz[0] - xyz[1] + 1) * (xyz[2] - xyz[3] + 1) * (xyz[4] - xyz[5] + 1);
	if (!(data->scene = malloc(sizeof(int) * i)))
		ft_free(data);
	while (i--)
		(data->scene)[i] = 0;
}

void	max_sphere(t_data *data, double *xyz)
{
	t_list	*tmp;
	double	r;

	tmp = data->sphere;
	while (tmp)
	{
		r = tmp->xx / 2;
		xyz[0] = tmp->x + r > xyz[0] ? tmp->x + r : xyz[0];
		xyz[1] = tmp->x - r < xyz[1] ? tmp->x - r : xyz[1];
		xyz[2] = tmp->y + r > xyz[2] ? tmp->y + r : xyz[2];
		xyz[3] = tmp->y - r < xyz[3] ? tmp->y - r : xyz[3];
		xyz[4] = tmp->z + r > xyz[4] ? tmp->z + r : xyz[4];
		xyz[5] = tmp->z - r < xyz[5] ? tmp->z - r : xyz[5];
		tmp = tmp->next;
	}
}

void	max_square(t_data *data, double *xyz)
{
	t_list	*tmp;
	double	h;

	tmp = data->square;
	while (tmp)
	{
		h = tmp->xxx;
		xyz[0] = tmp->x + h * tmp->xx > xyz[0] ? tmp->x + h *tmp->xx : xyz[0];
		xyz[1] = tmp->x + h * tmp->xx < xyz[1] ? tmp->x + h *tmp->xx : xyz[1];
		xyz[2] = tmp->y + h * tmp->xx > xyz[2] ? tmp->y + h *tmp->xx : xyz[2];
		xyz[3] = tmp->y + h * tmp->xx < xyz[3] ? tmp->y + h *tmp->xx : xyz[3];
		xyz[4] = tmp->z + h * tmp->xx > xyz[4] ? tmp->z + h *tmp->xx : xyz[4];
		xyz[5] = tmp->z + h * tmp->xx < xyz[5] ? tmp->z + h *tmp->xx : xyz[5];
		tmp = tmp->next;
	}
}

void	max_cylinder(t_data *data, double *xyz)
{
	t_list	*tmp;
	double	r;
	double	h;
	double	c;

	tmp = data->cylinder;
	while (tmp)
	{
		r = tmp->xxx / 2;
		h = tmp->xxy;
		c = r * (1 - fabs(tmp->xx));
		xyz[0] = tmp->x + c > xyz[0] ? tmp->x + c : xyz[0];
		xyz[1] = tmp->x - c < xyz[1] ? tmp->x - c : xyz[1];
		c = r * (1 - fabs(tmp->xy));
		xyz[2] = tmp->y + c > xyz[2] ? tmp->y + c : xyz[2];
		xyz[3] = tmp->y - c < xyz[3] ? tmp->y - c : xyz[3];
		c = r * (1 - fabs(tmp->xz));
		xyz[4] = tmp->z + c > xyz[4] ? tmp->z + c : xyz[4];
		xyz[5] = tmp->z - c < xyz[5] ? tmp->z - c : xyz[5];
		tmp = tmp->next;
	}
}

void	max_triangle(t_data *data, double *xyz)
{
	t_list	*tmp;

	tmp = data->triangle;
	while (tmp)
	{
		xyz[0] = tmp->x > xyz[0] ? tmp->x : xyz[0];
		xyz[0] = tmp->xx > xyz[0] ? tmp->xx : xyz[0];
		xyz[0] = tmp->xxx > xyz[0] ? tmp->xxx : xyz[0];
		xyz[1] = tmp->x < xyz[1] ? tmp->x : xyz[1];
		xyz[1] = tmp->xx < xyz[1] ? tmp->xx : xyz[1];
		xyz[1] = tmp->xxx < xyz[1] ? tmp->xxx : xyz[1];
		xyz[2] = tmp->y > xyz[2] ? tmp->y : xyz[2];
		xyz[2] = tmp->yy > xyz[2] ? tmp->yy : xyz[2];
		xyz[2] = tmp->yyy > xyz[2] ? tmp->yyy : xyz[2];
		xyz[3] = tmp->y < xyz[3] ? tmp->y : xyz[3];
		xyz[3] = tmp->yy < xyz[3] ? tmp->yy : xyz[3];
		xyz[3] = tmp->yyy < xyz[3] ? tmp->yyy : xyz[3];
		xyz[4] = tmp->z > xyz[4] ? tmp->z : xyz[4];
		xyz[4] = tmp->zz > xyz[4] ? tmp->zz : xyz[4];
		xyz[4] = tmp->zzz > xyz[4] ? tmp->zzz : xyz[4];
		xyz[5] = tmp->z < xyz[5] ? tmp->z : xyz[5];
		xyz[5] = tmp->zz < xyz[5] ? tmp->zz : xyz[5];
		xyz[5] = tmp->zzz < xyz[5] ? tmp->zzz : xyz[5];
		tmp = tmp->next;
	}
}
