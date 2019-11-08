/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:17:37 by yvanat            #+#    #+#             */
/*   Updated: 2019/11/08 14:06:52 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
//printf("%s\n", strerror(errno));
int     main(int argc, char **argv)
{
    t_data		*data;

	if (!(data = malloc(sizeof(t_data))))
		return (EXIT_FAILURE);
	if (argc == 2)
	{
		return (0);
	}
	if (argc == 3 && !ft_strcmp(argv[2], "-save"))
	{
		return (0);
	}
	data_init(data);
	ft_parse(argv[1], data);
	scene_matrix(data);
    if ((data->mlx_ptr = mlx_init()) == NULL)
	{
		ft_free(data);
        return (EXIT_FAILURE);
	}
    if ((data->win_ptr = mlx_new_window(data->mlx_ptr, data->x, data->y, "miniRT")) == NULL)
	{
		ft_free(data);
        return (EXIT_FAILURE);
	}
    mlx_key_hook(data->win_ptr, &key_hook, data);
	mlx_mouse_hook(data->win_ptr, &mouse_hook, data);
	mlx_loop_hook(data->mlx_ptr, &loop_hook, data);
	mlx_loop(data->mlx_ptr);
	ft_free(data);
    return (EXIT_SUCCESS);
}
