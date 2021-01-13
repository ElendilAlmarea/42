/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:46:17 by yvanat            #+#    #+#             */
/*   Updated: 2021/01/13 17:56:37 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

# define FORK " has taken a fork\n"
# define EAT " is eating\n"
# define SLEEP " is sleeping\n"
# define THINK " is thinking\n"
# define DIE " died\n"
# define NEED_EAT 0
# define NEED_SLEEP 1
# define NEED_THINK 2

typedef struct		s_thread
{
    int             alive;
    int             num_philo;
	int             nb_philo;
    int             t_die;
    int             t_eat;
    int             t_sleep;
    int             nb_eat;
    int             *forks;
    pthread_mutex_t mutex_forks;
    struct timeval  initial_time;
}                   t_thread;

int     diff_time_ms(struct timeval first, struct timeval second);
void	ft_putnbr_fd(int n, int fd);
int     ft_strlen(const char *s);
void    write_status(int timestamp, int philo, char *action, int alive);
int	    ft_atoi(const char *nptr);

#endif