/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:33:37 by yvanat            #+#    #+#             */
/*   Updated: 2019/10/31 14:24:17 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	eighth_if(t_var *var, t_func *func)
{
	if (!(var->left) && (!(var->zero) || var->staross))
		put_times_c(func->printed - func->len_p
				- (((var->staross - func->len_p) > 0)
				? (var->staross - func->len_p) : 0), ' ');
	if (var->zero && !(var->left) && !(var->staross))
		put_times_c(func->printed - func->len_p, '0');
	if (var->staross)
		put_times_c(var->staross - func->len_p, '0');
	if (func->len > 0)
		put_hex_rec(var->x, var->xx ? "0123456789ABCDEF" : "0123456789abcdef");
	if (var->left)
		put_times_c(func->printed - func->len_p - (((var->staross - func->len_p)
				> 0) ? (var->staross - func->len_p) : 0), ' ');
}

void	mall(t_var *var, va_list ap)
{
	char	*s;
	int		i;

	if (!(s = va_arg(ap, char*)))
		s = "(null)";
	if ((var->s = malloc(sizeof(char) * (ft_strlen(s) + 1))))
	{
		i = -1;
		while (s[++i])
			(var->s)[i] = s[i];
		(var->s)[i] = '\0';
		var->len += put_str(var);
		free(var->s);
	}
}

int		free_ret(int ret, t_func *func)
{
	free(func);
	return (ret);
}

int		put_format(t_var *var)
{
	if (var->zero && !(var->left))
		put_times_c(var->stari - 1, '0');
	else if (!(var->left))
		put_times_c(var->stari - 1, ' ');
	write(1, &(var->c), 1);
	if (var->left)
		put_times_c(var->stari - 1, ' ');
	return (var->stari ? var->stari : 1);
}
