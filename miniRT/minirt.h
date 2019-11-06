/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:05:57 by yvanat            #+#    #+#             */
/*   Updated: 2019/11/06 19:36:06 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>

typedef struct	s_list
{
	char			r;
	char			g;
	char			b;
	double			x;
	double			y;
	double			z;
	double			xx;
	double			yy;
	double			zz;
	double			xxx;
	double			yyy;
	double			zzz;
	struct s_list	*next;
}				t_list;

typedef struct	s_data
{
    void		*mlx_ptr;
    void		*win_ptr;
	void		*img_ptr;
	int			rx;
	int			ry;
	char		ar;
	char		ag;
	char		ab;
	double		al;
	t_list		*camera;
	t_list		*light;
	t_list		*plane;
	t_list		*sphere;
	t_list		*square;
	t_list		*cylinder;
	t_list		*triangle;
}				t_data;

int				key_hook(int keycode, t_data *data);
int				mouse_hook(int button, int x, int y, t_data *data);
int				loop_hook(t_data *data);
int				ft_strcmp(const char *s1, const char *s2);
int				parse_call(t_data *data, char *buffer, int i);
int				parse_r(t_data *data, char *buffer, int i);
int				parse_a(t_data *data, char *buffer, int i);
int				parse_c(t_data *data, char *buffer, int i);
int				parse_l(t_data *data, char *buffer, int i);
int				parse_pl(t_data *data, char *buffer, int i);
int				parse_sp(t_data *data, char *buffer, int i);
int				parse_sq(t_data *data, char *buffer, int i);
int				parse_cy(t_data *data, char *buffer, int i);
int				parse_tr(t_data *data, char *buffer, int i);
void			ft_parse(char *file, t_data *data);
void			ft_free(t_data *data);
void			put_error(ssize_t size);
void			data_init(t_list *data);

#endif