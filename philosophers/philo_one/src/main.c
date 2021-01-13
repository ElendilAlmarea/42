/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:45:56 by yvanat            #+#    #+#             */
/*   Updated: 2021/01/13 18:49:41 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *philosophers(void *data)
{
    t_thread        *thread;
    struct timeval  last_eat;
    struct timeval  now;
    int             num_philo;
    int             state;

    state = NEED_EAT;
    thread = (t_thread*)data;
    pthread_mutex_lock(&thread->mutex_forks);
    num_philo = (thread->num_philo)++;
    pthread_mutex_unlock(&thread->mutex_forks);
    last_eat = thread->initial_time;
    while (thread->alive)
    {
        gettimeofday(&now, NULL);
        if (diff_time_ms(now, last_eat) > thread->t_die)
        {
            pthread_mutex_lock(&thread->mutex_forks);
            write_status(diff_time_ms(now, thread->initial_time),
                num_philo, DIE, thread->alive);
            thread->alive = 0;
            pthread_mutex_unlock(&thread->mutex_forks);
            continue ;
        }
        if (state == NEED_EAT)
        {
            pthread_mutex_lock(&thread->mutex_forks);
            if (thread->forks[num_philo] && (num_philo == thread->nb_philo - 1 ?
                thread->forks[0] : thread->forks[num_philo + 1]))
            {
                (thread->forks[num_philo])--;
                num_philo == thread->nb_philo - 1 ? (thread->forks[0])-- :
                    (thread->forks[num_philo + 1])--;
                write_status(diff_time_ms(now, thread->initial_time),
                    num_philo, FORK, thread->alive);
                write_status(diff_time_ms(now, thread->initial_time),
                    num_philo, FORK, thread->alive);
                write_status(diff_time_ms(now, thread->initial_time),
                    num_philo, EAT, thread->alive);
                state = NEED_SLEEP;
            }
            pthread_mutex_unlock(&thread->mutex_forks);
            if (state == NEED_SLEEP)
            {
                usleep(thread->t_eat * 1000);
                gettimeofday(&last_eat, NULL);
                pthread_mutex_lock(&thread->mutex_forks);
                (thread->forks[num_philo])++;
                num_philo == thread->nb_philo - 1 ? (thread->forks[0])++ :
                    (thread->forks[num_philo + 1])++;
                pthread_mutex_unlock(&thread->mutex_forks);
                continue ;
            }
        }
        if (state == NEED_SLEEP)
        {
            state = NEED_THINK;
            write_status(diff_time_ms(now, thread->initial_time),
                    num_philo, SLEEP, thread->alive);
            usleep(thread->t_sleep * 1000);
            continue ;
        }
        if (state == NEED_THINK)
        {
            write_status(diff_time_ms(now, thread->initial_time),
                    num_philo, THINK, thread->alive);
            state = NEED_EAT;
        }
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
    thread->num_philo = 0;
    thread->alive = 1;
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
        pthread_create(&philo[i], NULL, philosophers, (void*)thread);
    i = -1;
    while (++i < thread->nb_philo)
        pthread_join(philo[i], NULL);
    pthread_mutex_destroy(&thread->mutex_forks);

    return (0);
}
