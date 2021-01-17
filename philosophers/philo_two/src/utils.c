/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:24:24 by yvanat            #+#    #+#             */
/*   Updated: 2021/01/16 22:09:23 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		diff_time_ms(struct timeval first, struct timeval second)
{
	return ((int)(1000 * (first.tv_sec - second.tv_sec) + 0.001 *
		(first.tv_usec - second.tv_usec)));
}

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

int		ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	write_status(int timestamp, int philo, char *action, int alive)
{
	if (alive)
	{
		ft_putnbr_fd(timestamp, 1);
		write(1, " ", 1);
		ft_putnbr_fd(philo + 1, 1);
		write(1, action, ft_strlen(action));
	}
}

int		ft_atoi(const char *nptr)
{
	int i;
	int neg;
	int nb;

	nb = 0;
	neg = 1;
	i = 0;
	while (nptr[i] == '\t' || nptr[i] == '\n' || nptr[i] == '\v'
		|| nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		nb *= 10;
		nb += nptr[i] - 48;
		i++;
	}
	return (nb * neg);
}
