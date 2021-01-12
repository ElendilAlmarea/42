/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:45:56 by yvanat            #+#    #+#             */
/*   Updated: 2021/01/12 19:10:52 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *philosophers(void *data)
{
    t_thread        *thread;
    struct timeval  last_eat;
    struct timeval  now;

    thread = (t_thread*)data;
    last_eat = thread->initial_time;
    while (1)
    {
        gettimeofday(&now, NULL);
        if (diff_time_ms(now, last_eat) > thread->t_die)
        {
            write_status(diff_time_ms(now, thread->initial_time),
                thread->num_philo, DIE);
            exit(0);
        }
        pthread_mutex_lock(&thread->mutex_forks);
        pthread_mutex_unlock(&thread->mutex_forks);
    }
    return (NULL);
}

int main(int argc, char **argv)
{
    pthread_t   philo[ft_atoi(argv[1])];
    int         i;
    t_thread    *thread;

    if (!(thread = malloc(sizeof(t_thread))))
		return (-1);
    thread->nb_philo = ft_atoi(argv[1]);
    thread->t_die = ft_atoi(argv[2]);
    thread->t_eat = ft_atoi(argv[3]);
    thread->t_sleep = ft_atoi(argv[4]);
    if (!(thread->forks = malloc(sizeof(int) * thread->nb_philo)))
        return (-1);
    if (argc == 6)
        thread->nb_eat = ft_atoi(argv[5]);
    pthread_mutex_init(&thread->mutex_forks, NULL);
    i = -1;
    while (++i < thread->nb_philo)
        thread->forks[i] = 1;
    i = -1;
    gettimeofday(&thread->initial_time, NULL);
    while (++i < thread->nb_philo)
    {
        thread->num_philo = i;
        pthread_create(&philo[i], NULL, philosophers, (void*)thread);
    }
    i = -1;
    while (++i < thread->nb_philo)
        pthread_join(philo[i], NULL);
    pthread_mutex_destroy(&thread->mutex_forks);

    return (0);
}
