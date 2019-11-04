/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:05:57 by yvanat            #+#    #+#             */
/*   Updated: 2019/11/04 18:45:31 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>

typedef struct	s_data
{
    void		*mlx_ptr;
    void		*win_ptr;
	void		*img_ptr;
	int			rx;
	int			ry;
	int			ar;
	int			ag;
	int			ab;
	float		al;
}				t_data;

int				key_hook(int keycode, t_data *data);
int				mouse_hook(int button, int x, int y, t_data *data);
int				loop_hook(t_data *data);
int				ft_strcmp(const char *s1, const char *s2);
void			ft_parse(t_data *data);

#endif