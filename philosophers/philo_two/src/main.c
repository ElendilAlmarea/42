/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:45:56 by yvanat            #+#    #+#             */
/*   Updated: 2021/01/17 17:03:42 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_var(t_thread *thread, t_tvar *var)
{
	pthread_mutex_lock(&thread->mutex_forks);
	var->num_philo = (thread->num_philo)++;
	pthread_mutex_unlock(&thread->mutex_forks);
	var->state = NEED_EAT;
	var->last_eat = thread->initial_time;
}

void	*philosophers(void *data)
{
	t_thread		*thread;
	t_tvar			*var;

	thread = (t_thread*)data;
	if (!(var = malloc(sizeof(t_tvar))))
		return (NULL);
	init_var(thread, var);
	while (thread->alive)
	{
		gettimeofday(&(var->now), NULL);
		if (thread->nb_eat >= 0 &&
			nb_eat(thread->tab_eat, thread->nb_eat, thread->nb_philo))
		{
			thread->alive = 0;
			continue ;
		}
		if (diff_time_ms(var->now, var->last_eat) > thread->t_die)
		{
			pthread_mutex_lock(&thread->mutex_forks);
			write_status(diff_time_ms(var->now, thread->initial_time),
				var->num_philo, DIE, thread->alive);
			thread->alive = 0;
			pthread_mutex_unlock(&thread->mutex_forks);
			continue ;
		}
		if (var->state == NEED_EAT)
		{
			pthread_mutex_lock(&thread->mutex_forks);
			if (thread->forks[var->num_philo] && (var->num_philo == thread->nb_philo
				- 1 ? thread->forks[0] : thread->forks[var->num_philo + 1]))
			{
				(thread->forks[var->num_philo])--;
				var->num_philo == thread->nb_philo - 1 ? (thread->forks[0])-- :
					(thread->forks[var->num_philo + 1])--;
				write_status(diff_time_ms(var->now, thread->initial_time),
					var->num_philo, FORK, thread->alive);
				write_status(diff_time_ms(var->now, thread->initial_time),
					var->num_philo, FORK, thread->alive);
				write_status(diff_time_ms(var->now, thread->initial_time),
					var->num_philo, EAT, thread->alive);
				pthread_mutex_unlock(&thread->mutex_forks);
				var->state = NEED_SLEEP;
			}
			else
			{
				pthread_mutex_unlock(&thread->mutex_forks);
				usleep(100);
			}
			if (var->state == NEED_SLEEP)
			{
				gettimeofday(&(var->last_eat), NULL);
				usleep(thread->t_eat * 1000);
				(thread->tab_eat[var->num_philo])++;
				pthread_mutex_lock(&thread->mutex_forks);
				(thread->forks[var->num_philo])++;
				var->num_philo == thread->nb_philo - 1 ? (thread->forks[0])++ :
					(thread->forks[var->num_philo + 1])++;
				pthread_mutex_unlock(&thread->mutex_forks);
				continue ;
			}
		}
		if (var->state == NEED_SLEEP)
		{
			var->state = NEED_THINK;
			pthread_mutex_lock(&thread->mutex_forks);
			write_status(diff_time_ms(var->now, thread->initial_time),
					var->num_philo, SLEEP, thread->alive);
			pthread_mutex_unlock(&thread->mutex_forks);
			usleep(thread->t_sleep * 1000);
			continue ;
		}
		if (var->state == NEED_THINK)
		{
			pthread_mutex_lock(&thread->mutex_forks);
			write_status(diff_time_ms(var->now, thread->initial_time),
					var->num_philo, THINK, thread->alive);
			pthread_mutex_unlock(&thread->mutex_forks);
			var->state = NEED_EAT;
		}
	}
	return (NULL);
}

void	init_struct(t_thread *thread, int argc, char **argv)
{
	int				i;

	thread->nb_philo = ft_atoi(argv[1]);
	thread->t_die = ft_atoi(argv[2]);
	thread->t_eat = ft_atoi(argv[3]);
	thread->t_sleep = ft_atoi(argv[4]);
	thread->num_philo = 0;
	thread->alive = 1;
	if (argc == 6)
		thread->nb_eat = ft_atoi(argv[5]);
	else
		thread->nb_eat = -1;
	i = -1;
	while (++i < thread->nb_philo)
	{
		thread->tab_eat[i] = 0;
		thread->forks[i] = 1;
	}
}

int		main(int argc, char **argv)
{
	pthread_t		philo[ft_atoi(argv[1])];
	int				i;
	t_thread		*thread;

	if (argc < 5 || argc > 6)
		return (-1);
	if (!(thread = malloc(sizeof(t_thread))))
		return (-1);
	if (!(thread->tab_eat = malloc(sizeof(int) * thread->nb_philo)))
		return (-1);
	if (!(thread->forks = malloc(sizeof(int) * thread->nb_philo)))
		return (-1);
	init_struct(thread, argc, argv);
	pthread_mutex_init(&thread->mutex_forks, NULL);
	i = -1;
	gettimeofday(&thread->initial_time, NULL);
	while (++i < thread->nb_philo)
		if (pthread_create(&philo[i], NULL, philosophers, (void*)thread))
			return (-1);
	i = -1;
	while (++i < thread->nb_philo)
		pthread_join(philo[i], NULL);
	pthread_mutex_destroy(&thread->mutex_forks);
	return (0);
}
