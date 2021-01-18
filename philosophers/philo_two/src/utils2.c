/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:32:54 by yvanat            #+#    #+#             */
/*   Updated: 2021/01/18 16:43:54 by yvanat           ###   ########.fr       */
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

int		free_ret(void *one, void *two, void *three, void *four)
{
	if (one)
		free(one);
	if (two)
		free(two);
	if (three)
		free(three);
	if (four)
		free(four);
	return (-1);
}

int		init_struct(t_thread **thread, t_tvar **var,
	int argc, char **argv)
{
	if (!(*thread = malloc(sizeof(t_thread) * ft_atoi(argv[1]))))
		return (-1);
	if (!(*var = malloc(sizeof(t_tvar))))
		return (free_ret(thread, NULL, NULL, NULL));
	pthread_mutex_init(&((*var)->mutex_forks), NULL);
	(*var)->nb_philo = ft_atoi(argv[1]);
	(*var)->t_die = ft_atoi(argv[2]);
	(*var)->t_eat = ft_atoi(argv[3]);
	(*var)->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		(*var)->nb_eat = ft_atoi(argv[5]);
	else
		(*var)->nb_eat = -1;
	if (!((*var)->tab_eat = malloc(sizeof(int) * ft_atoi(argv[1]))))
		return (free_ret(thread, var, NULL, NULL));
	if (!((*var)->forks = malloc(sizeof(int) * ft_atoi(argv[1]))))
		return (free_ret(thread, (*var)->tab_eat, *var, NULL));
	(*var)->alive = -1;
	while (++((*var)->alive) < (*var)->nb_philo)
	{
		(*var)->tab_eat[(*var)->alive] = 0;
		(*var)->forks[(*var)->alive] = 1;
	}
	(*var)->alive = 1;
	return (0);
}
