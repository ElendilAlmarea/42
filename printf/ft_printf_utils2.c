/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:48:03 by yvanat            #+#    #+#             */
/*   Updated: 2019/10/16 17:04:48 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		put_times_c(int nb, char c)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		write(1, &c, 1);
		i++;
	}
}

int			ft_strlen(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void		put_hex_rec(unsigned int nb, char *base)
{
	unsigned int	quotient;
	unsigned int	remainder;

	quotient = nb / 16;
	remainder = nb % 16;
	if (quotient)
		put_hex_rec(quotient, base);
	write(1, base + remainder, 1);
}

void		put_hex_rec_long(long nb, char *base)
{
	long	quotient;
	long	remainder;

	quotient = nb / 16;
	remainder = nb % 16;
	if (quotient)
		put_hex_rec_long(quotient, base);
	write(1, base + remainder, 1);
}

int			put_hex(t_var *var)
{
	t_func	*func;

	if (!(func = malloc(sizeof(t_func))))
		return (0);
	func->len = 0;
	func->unb = var->x;
	while ((func->unb != 0 || func->len == 0)
			&& (var->staross != -1 || var->x != 0))
	{
		func->unb /= 16;
		(func->len)++;
	}
	func->len_p = func->len;
	func->printed = (var->staross > var->stari) ? var->staross : var->stari;
	func->printed = (func->printed > func->len_p) ? func->printed : func->len_p;
	eighth_if(var, func);
	return (free_ret(func->printed, func));
}
