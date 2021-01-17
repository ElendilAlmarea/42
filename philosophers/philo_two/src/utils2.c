/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:32:54 by yvanat            #+#    #+#             */
/*   Updated: 2021/01/17 16:06:28 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		nb_eat(int *tab_eat, int nb_eat, int nb_philo)
{
	while (nb_philo-- > 0)
	{
		if (tab_eat[nb_philo] < nb_eat)
			return (0);
	}
	return (1);
}
