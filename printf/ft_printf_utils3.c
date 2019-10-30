/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:22:43 by yvanat            #+#    #+#             */
/*   Updated: 2019/10/30 12:19:42 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_var(t_var *var)
{
	var->power = 10;
	var->left = 0;
	var->zero = 0;
	var->precision = 0;
	var->stari = 0;
	var->staross = 0;
}

void	first_while(const char *format, t_var *var, va_list ap)
{
	while (format[var->i])
	{
		init_var(var);
		if (format[var->i] == '%')
		{
			(var->i)++;
			second_while(format, var, ap);
		}
		else
		{
			write(1, &format[var->i], 1);
			var->len++;
			(var->i)++;
		}
	}
}

void	second_while(const char *format, t_var *var, va_list ap)
{
	while (format[var->i])
	{
		first_if(format, var, ap);
		if (format[var->i] == 'c' || format[var->i] == 's' || format[var->i]
			== 'p' || format[var->i] == 'd' || format[var->i] == 'i' ||
			format[var->i] == 'u' || format[var->i] == 'x' || format[var->i]
			== 'X' || format[var->i] == '%')
		{
			third_if(format, var, ap);
			if (format[var->i] == '%')
			{
				var->c = '%';
				var->len += put_char(var);
			}
			fourth_if(format, var, ap);
			(var->i)++;
			break ;
		}
		(var->i)++;
	}
}

void	first_if(const char *format, t_var *var, va_list ap)
{
	if (format[var->i] == '-')
	{
		var->left = 1;
		var->zero = 0;
	}
	else if (format[var->i] == '0')
		var->zero = 1;
	else if (format[var->i] == '.')
		var->precision = 1;
	else if (format[var->i] == '*')
	{
		if (!var->precision)
			var->stari = va_arg(ap, int);
		else
			var->staross = va_arg(ap, int);
	}
	else if (format[var->i] >= 49 && format[var->i] <= 57)
		second_if(format, var);
}

void	second_if(const char *format, t_var *var)
{
	if (!(var->precision))
		var->stari = format[var->i] - 48;
	else
		var->staross = format[var->i] - 48;
	var->power = 10;
	while (format[var->i + 1] >= 48 && format[var->i + 1] <= 57)
	{
		(var->i)++;
		if (!(var->precision))
			var->stari = var->stari * var->power + format[var->i] - 48;
		else
			var->staross = var->staross * var->power + format[var->i] - 48;
		var->power *= 10;
	}
}
