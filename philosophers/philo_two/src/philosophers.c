/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:02:40 by yvanat            #+#    #+#             */
/*   Updated: 2021/01/18 17:59:45 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	sem_wait(thread->var->forks);
	sem_wait(thread->var->forks);
	write_status(thread, FORK);
	write_status(thread, FORK);
	write_status(thread, EAT);
	thread->state = NEED_SLEEP;
}

int		eating(t_thread *thread)
{
	if (thread->state == NEED_SLEEP)
	{
		gettimeofday(&(thread->last_eat), NULL);
		usleep(thread->var->t_eat * 1000);
		(thread->var->tab_eat[thread->num_philo])++;
		sem_post(thread->var->forks);
		sem_post(thread->var->forks);
		return (1);
	}
	return (0);
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
