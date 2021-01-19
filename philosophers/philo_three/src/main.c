/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:45:56 by yvanat            #+#    #+#             */
/*   Updated: 2021/01/19 17:14:21 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*wait_alive(void *data)
{
	t_tvar			*var;
	int				i;

	var = (t_tvar*)data;
	sem_wait(var->alive);
	var->t_die = -1;
	i = -1;
	while (++i < var->nb_philo * var->nb_eat)
		sem_post(var->tab_eat);
	return (NULL);
}

void	*wait_tab_eat(void *data)
{
	t_tvar			*var;
	int				i;

	var = (t_tvar*)data;
	i = -1;
	while (++i < var->nb_philo * var->nb_eat)
		sem_wait(var->tab_eat);
	if (var->t_die != -1 && var->nb_eat >= 0)
	{
		sem_wait(var->status);
		sem_post(var->alive);
	}
	return (NULL);
}

int		main(int argc, char **argv)
{
	int				i;
	t_thread		*thread;
	t_tvar			*var;
	pthread_t		semaphore[2];

	if (argc < 5 || argc > 6 || init_struct(&thread, &var, argc, argv))
		return (-1);
	i = -1;
	gettimeofday(&(var->initial_time), NULL);
	while (++i < var->nb_philo)
	{
		thread[i].num_philo = i;
		thread[i].state = NEED_EAT;
		thread[i].var = var;
		thread[i].last_eat = var->initial_time;
		if (!(thread[i].pid = fork()))
			philosophers(thread + i);
	}
	pthread_create(&semaphore[0], NULL, wait_alive, var);
	pthread_create(&semaphore[1], NULL, wait_tab_eat, var);
	pthread_join(semaphore[0], NULL);
	pthread_join(semaphore[1], NULL);
	end(thread);
	return (0);
}
