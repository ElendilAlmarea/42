/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 23:12:50 by yvanat            #+#    #+#             */
/*   Updated: 2020/02/07 23:12:51 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/h_minirt.h"

t_vec	add_vec(t_vec vec1, t_vec vec2)
{
	vec1.x += vec2.x;
	vec1.y += vec2.y;
	vec1.z += vec2.z;
	return (vec1);
}

t_vec	sub_vec(t_vec vec1, t_vec vec2)
{
	vec1.x -= vec2.x;
	vec1.y -= vec2.y;
	vec1.z -= vec2.z;
	return (vec1);
}

t_vec	mult_vec(t_vec vec1, t_vec vec2)
{
	vec1.x *= vec2.x;
	vec1.y *= vec2.y;
	vec1.z *= vec2.z;
	return (vec1);
}

t_vec	div_vec(t_vec vec1, t_vec vec2)
{
	vec1.x /= vec2.x;
	vec1.y /= vec2.y;
	vec1.z /= vec2.z;
	return (vec1);
}
