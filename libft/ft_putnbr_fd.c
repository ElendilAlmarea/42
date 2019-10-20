/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:37:58 by yvanat            #+#    #+#             */
/*   Updated: 2019/10/12 14:06:24 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		len;
	int		nb;
	char	c;

	len = 0;
	nb = n;
	while (nb != 0 || len == 0)
	{
		nb /= 10;
		len++;
	}
	if (!(nb++) && n < 0)
		write(fd, "-", 1);
	while (len-- > 1)
		nb *= 10;
	while (nb > 0)
	{
		if (n < 0)
			c = (n / nb) * -1 + 48;
		else
			c = n / nb + 48;
		write(fd, &c, 1);
		n -= (n / nb) * nb;
		nb /= 10;
	}
}
