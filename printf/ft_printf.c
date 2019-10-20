/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:54:03 by yvanat            #+#    #+#             */
/*   Updated: 2019/10/16 17:44:18 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_var	*var;
	va_list	ap;
	int		len;

	if (!(var = malloc(sizeof(t_var))))
		return (0);
	va_start(ap, format);
	var->len = 0;
	var->i = 0;
	first_while(format, var, ap);
	va_end(ap);
	len = var->len;
	free(var);
	return (len);
}
