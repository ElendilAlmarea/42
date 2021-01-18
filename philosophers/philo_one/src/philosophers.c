/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:02:40 by yvanat            #+#    #+#             */
/*   Updated: 2021/01/18 17:03:00 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		check_philo(t_thread *thread)
{
	gettimeofday(&(thread->now), NULL);
	if (thread->var->nb_eat >= 0 &&
		nb_eat(thread->var->tab_eat, thread->var->nb_eat,
			thread->var->nb_philo))
	{
		thread->var->alive = 0;
		return (1);
	}
	if (diff_time_ms(thread->now, thread->last_eat) > thread->var->t_die)
	{
		thread->var->alive = 0;
		thread->state = DEAD;
		write_status(thread, DIE);
		return (1);
	}
	return (0);
}

void	eat(t_thread *thread)
{
	pthread_mutex_lock(&(thread->var->mutex_forks));
	if (thread->var->forks[thread->num_philo] && ((thread->num_philo ==
		thread->var->nb_philo - 1 && thread->var->forks[0]) ||
		(thread->num_philo != thread->var->nb_philo - 1 &&
		thread->var->forks[thread->num_philo + 1])))
	{
		(thread->var->forks[thread->num_philo])--;
		if (thread->num_philo == thread->var->nb_philo - 1)
			(thread->var->forks[0])--;
		else
			(thread->var->forks[thread->num_philo + 1])--;
		pthread_mutex_unlock(&(thread->var->mutex_forks));
		write_status(thread, FORK);
		write_status(thread, FORK);
		write_status(thread, EAT);
		thread->state = NEED_SLEEP;
	}
	else
	{
		pthread_mutex_unlock(&(thread->var->mutex_forks));
		usleep(100);
	}
}

int		eating(t_thread *thread)
{
	if (thread->state == NEED_SLEEP)
	{
		gettimeofday(&(thread->last_eat), NULL);
		usleep(thread->var->t_eat * 1000);
		(thread->var->tab_eat[thread->num_philo])++;
		pthread_mutex_lock(&(thread->var->mutex_forks));
		(thread->var->forks[thread->num_philo])++;
		if (thread->num_philo == thread->var->nb_philo - 1)
			(thread->var->forks[0])++;
		else
			(thread->var->forks[thread->num_philo + 1])++;
		pthread_mutex_unlock(&(thread->var->mutex_forks));
		return (1);
	}
	return (0);
}

void	*philosophers(void *data)
{
	t_thread		*thread;

	thread = (t_thread*)data;
	while (thread->var->alive)
	{
		if (check_philo(thread))
			continue ;
		if (thread->state == NEED_EAT)
		{
			eat(thread);
			if (eating(thread))
				continue ;
		}
		sleep_think(thread);
	}
	return (NULL);
}

void	sleep_think(t_thread *thread)
{
	if (thread->state == NEED_SLEEP)
	{
		thread->state = NEED_THINK;
		write_status(thread, SLEEP);
		usleep(thread->var->t_sleep * 1000);
	}
	else if (thread->state == NEED_THINK)
	{
		write_status(thread, THINK);
		thread->state = NEED_EAT;
	}
}
