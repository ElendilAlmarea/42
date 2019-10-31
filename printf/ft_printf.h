/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 11:35:04 by yvanat            #+#    #+#             */
/*   Updated: 2019/10/31 14:00:38 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_var
{
	char			c;
	int				i;
	int				di;
	int				power;
	int				len;
	int				left;
	int				zero;
	int				precision;
	int				stari;
	int				staross;
	unsigned int	u;
	unsigned int	x;
	unsigned int	xx;
	char			*s;
}				t_var;

typedef struct	s_func
{
	int				len;
	int				len_p;
	int				nb;
	unsigned int	unb;
	char			c;
	int				printed;
	int				neg;
}				t_func;

int				put_format(t_var *var);
int				ft_printf(const char *format, ...);
int				put_char(t_var *var);
int				put_str(t_var *var);
int				put_ptr(t_var *var, void *p);
int				put_int(t_var *var);
int				put_unsint(t_var *var);
int				put_hex(t_var *var);
void			put_times_c(int nb, char c);
int				ft_strlen(char *s);
void			put_hex_rec(unsigned int nb, char *base);
void			put_hex_rec_long(long nb, char *base);
int				put_hex(t_var *var);
void			init_var(t_var *var);
void			first_while(const char *format, t_var *var, va_list ap);
void			second_while(const char *format, t_var *var, va_list ap);
void			first_if(const char *format, t_var *var, va_list ap);
void			second_if(const char *format, t_var *var);
void			third_if(const char *format, t_var *var, va_list ap);
void			fourth_if(const char *format, t_var *var, va_list ap);
void			fifth_if(t_var *var, t_func *func);
void			sixth_if(t_var *var, t_func *func);
void			seventh_if(t_var *var, t_func *func);
void			eighth_if(t_var *var, t_func *func);
void			mall(t_var *var, va_list ap);
int				free_ret(int ret, t_func *func);

#endif
