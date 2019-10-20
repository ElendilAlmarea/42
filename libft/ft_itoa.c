/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:18:03 by yvanat            #+#    #+#             */
/*   Updated: 2019/10/12 15:34:27 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_second(char *new, int n, int index, int len)
{
	int	i;

	i = 1;
	while (len > 1)
	{
		i *= 10;
		len--;
	}
	while (i > 0)
	{
		if (n < 0)
			new[index] = (n / i) * -1 + 48;
		else
			new[index] = (n / i) + 48;
		n -= (n / i) * i;
		i /= 10;
		index++;
	}
	return (new);
}

char		*ft_itoa(int n)
{
	int		len;
	int		nb;
	int		neg;
	char	*new;

	len = 0;
	nb = n;
	while (nb != 0 || len == 0)
	{
		nb /= 10;
		len += 1;
	}
	neg = 0;
	if (n < 0)
		neg = 1;
	if (!(new = malloc(sizeof(*new) * (len + neg + 1))))
		return (NULL);
	if (neg)
		new[0] = '-';
	return (ft_itoa_second(new, n, neg, len));
}
