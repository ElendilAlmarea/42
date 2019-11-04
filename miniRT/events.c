/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:22:31 by yvanat            #+#    #+#             */
/*   Updated: 2019/11/04 18:39:56 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		key_hook(int keycode, t_data *data)
{
	if (keycode == 49)
	{
		return (0);
	}
    if (keycode == 53)
	{
	    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		ft_free(data);
		exit(EXIT_SUCCESS);
	}
	printf("%d", keycode);
    return (0);
}

int		mouse_hook(int button, int x, int y, t_data *data)
{
	return (0);
}

int		loop_hook(t_data *data)
{
	return (0);
}
