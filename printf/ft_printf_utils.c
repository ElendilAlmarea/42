/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:49:44 by yvanat            #+#    #+#             */
/*   Updated: 2019/10/31 15:39:54 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		put_char(t_var *var)
{
	if (!(var->left))
		put_times_c(var->stari - 1, ' ');
	write(1, &(var->c), 1);
	if (var->left)
		put_times_c(var->stari - 1, ' ');
	return (var->stari ? var->stari : 1);
}

int		put_str(t_var *var)
{
	int			printed;

	if (var->staross)
	{
		if (var->staross == -1)
			var->staross = 0;
		printed = (ft_strlen(var->s) > var->staross)
				? var->staross : ft_strlen(var->s);
	}
	else
		printed = ft_strlen(var->s);
	if (!(var->left))
		put_times_c(var->stari - printed, ' ');
	write(1, var->s, printed);
	if (var->left)
		put_times_c(var->stari - printed, ' ');
	return ((var->stari > printed) ? var->stari : printed);
}

int		put_ptr(t_var *var, void *p)
{
	int			len;
	long		addr;
	long		nb;

	addr = (long)(p);
	nb = addr;
	len = 2;
	while (nb != 0 || len == 2)
	{
		nb /= 16;
		len++;
	}
	if (!(var->left))
		put_times_c(var->stari - len, ' ');
	write(1, "0x", 2);
	put_hex_rec_long(addr, "0123456789abcdef");
	if (var->left)
		put_times_c(var->stari - len, ' ');
	return ((len > var->stari) ? len : var->stari);
}

int		put_int(t_var *var)
{
	t_func	*func;

	if (!(func = malloc(sizeof(t_func))))
		return (0);
	fifth_if(var, func);
	sixth_if(var, func);
	return (free_ret(func->printed, func));
}

int		put_unsint(t_var *var)
{
	t_func	*func;

	if (!(func = malloc(sizeof(t_func))))
		return (0);
	seventh_if(var, func);
	if (func->len > 0)
	{
		func->unb = 1;
		while ((func->len)-- > 1)
			func->unb *= 10;
		while (func->unb > 0)
		{
			func->c = var->u / func->unb + 48;
			write(1, &(func->c), 1);
			var->u -= (var->u / func->unb) * func->unb;
			func->unb /= 10;
		}
	}
	if (var->left)
		put_times_c(func->printed - func->len_p - (((var->staross - func->len_p)
				> 0) ? (var->staross - func->len_p) : 0), ' ');
	return (free_ret(func->printed, func));
}
