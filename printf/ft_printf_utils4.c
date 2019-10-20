/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 14:17:59 by yvanat            #+#    #+#             */
/*   Updated: 2019/10/16 17:19:51 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	third_if(const char *format, t_var *var, va_list ap)
{
	if (var->stari < 0)
	{
		var->stari *= -1;
		var->left = 1;
		var->zero = 0;
	}
	if (var->staross < 0)
	{
		var->staross = 0;
		var->precision = 0;
	}
	if (var->precision && !var->staross)
		var->staross = -1;
	if (format[var->i] == 'c')
	{
		var->c = (char)va_arg(ap, int);
		var->len += put_char(var);
	}
	else if (format[var->i] == 's')
		mall(var, ap);
}

void	fourth_if(const char *format, t_var *var, va_list ap)
{
	void	*p;

	if (format[var->i] == 'p')
	{
		p = va_arg(ap, void*);
		var->len += put_ptr(var, p);
	}
	else if (format[var->i] == 'd' || format[var->i] == 'i')
	{
		var->di = va_arg(ap, int);
		var->len += put_int(var);
	}
	else if (format[var->i] == 'u')
	{
		var->u = va_arg(ap, unsigned int);
		var->len += put_unsint(var);
	}
	else if (format[var->i] == 'x' || format[var->i] == 'X')
	{
		var->x = va_arg(ap, unsigned int);
		var->xx = 0;
		if (format[var->i] == 'X')
			var->xx = 1;
		var->len += put_hex(var);
	}
}

void	fifth_if(t_var *var, t_func *func)
{
	func->neg = 0;
	if (var->di < 0)
		func->neg = 1;
	func->len = 0;
	func->nb = var->di;
	while ((func->nb != 0 || func->len == 0) && (var->staross != -1 ||
		var->di != 0))
	{
		func->nb /= 10;
		(func->len)++;
	}
	func->len_p = func->len;
	func->printed = (var->staross > var->stari) ? (var->staross + func->neg) :
		var->stari;
	func->printed = (func->printed > func->len_p + func->neg) ? func->printed :
		(func->len_p + func->neg);
	if (!(var->left) && (!(var->zero) || var->staross))
		put_times_c(func->printed - func->len_p - func->neg - (((var->staross -
			func->len_p) > 0) ? (var->staross - func->len_p) : 0), ' ');
	if (func->neg)
		write(1, "-", 1);
	if (var->zero && !(var->left) && !(var->staross))
		put_times_c(func->printed - func->len_p - func->neg, '0');
}

void	sixth_if(t_var *var, t_func *func)
{
	if (var->staross)
		put_times_c(var->staross - func->len_p, '0');
	if (func->len > 0)
	{
		func->nb = 1;
		while ((func->len)-- > 1)
			func->nb *= 10;
		while (func->nb > 0)
		{
			if (var->di < 0)
				func->c = (var->di / func->nb) * -1 + 48;
			else
				func->c = var->di / func->nb + 48;
			write(1, &(func->c), 1);
			var->di -= (var->di / func->nb) * func->nb;
			func->nb /= 10;
		}
	}
	if (var->left)
		put_times_c(func->printed - func->len_p - func->neg - (((var->staross -
			func->len_p) > 0) ? (var->staross - func->len_p) : 0), ' ');
}

void	seventh_if(t_var *var, t_func *func)
{
	func->len = 0;
	func->nb = var->u;
	while ((func->nb != 0 || func->len == 0) &&
		(var->staross != -1 || var->u != 0))
	{
		func->nb /= 10;
		(func->len)++;
	}
	func->len_p = func->len;
	func->printed = (var->staross > var->stari) ? var->staross : var->stari;
	func->printed = (func->printed > func->len_p) ? func->printed : func->len_p;
	if (!(var->left) && (!(var->zero) || var->staross))
		put_times_c(func->printed - func->len_p - (((var->staross - func->len_p)
			> 0) ? (var->staross - func->len_p) : 0), ' ');
	if (var->zero && !(var->left) && !(var->staross))
		put_times_c(func->printed - func->len_p, '0');
	if (var->staross)
		put_times_c(var->staross - func->len_p, '0');
}
