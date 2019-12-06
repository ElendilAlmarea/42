/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:05:57 by yvanat            #+#    #+#             */
/*   Updated: 2019/12/06 17:00:30 by yvanat           ###   ########.fr       */
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
	double		x_bias;
	double		y_bias;
	double		z_bias;
	int			x;
	int			y;
	int			z;
	int			*scene;
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
int				white_space(char c);
int				ft_isdigit(int c);
int				parse_rgb(t_data *data, char *buffer, int i, t_list *tmp);
int				parse_xyz(t_data *data, char *buffer, int i, t_list *tmp);
int				parse_y(t_data *data, char *buffer, int i, t_list *tmp);
int				parse_z(t_data *data, char *buffer, int i, t_list *tmp);
int				parse_xxyyzz(t_data *data, char *buffer, in it, t_list *tmp);
int				parse_yy(t_data *data, char *buffer, int i, t_list *tmp);
int				parse_zz(t_data *data, char *buffer, int i, t_list *tmp);
int				parse_xxxyyyzzz(t_data *data, char *buffer, int i, t_list *tmp);
int				parse_yyy(t_data *data, char *buffer, int i, t_list *tmp);
int				parse_zzz(t_data *data, char *buffer, int i, t_list *tmp);
void			ft_parse(char *file, t_data *data);
void			ft_free(t_data *data);
void			put_error(ssize_t size);
void			data_init(t_list *data);
void			scene_matrix(t_data *data);
void			max_sphere(t_data *data, double *xyz);
void			max_square(t_data *data, double *xyz);
void			max_cylinder(t_data *data, double *xyz);
void			max_triangle(t_data *data, double *xyz);
void			fill_scene(t_data *data);
void			fill_plane(t_data *data, t_list *tmp);
void			fill_sphere(t_data *data, t_list *tmp);
void			fill_square(t_data *data, t_list *tmp);
void			fill_cylinder(t_data *data, t_list *tmp);
void			fill_triangle(t_data *data, t_list *tmp);
void			raytracing(t_data *data);

#endif