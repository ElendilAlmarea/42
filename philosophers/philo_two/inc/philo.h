/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:46:17 by yvanat            #+#    #+#             */
/*   Updated: 2021/01/18 17:03:27 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <string.h>

# define FORK " has taken a fork\n"
# define EAT " is eating\n"
# define SLEEP " is sleeping\n"
# define THINK " is thinking\n"
# define DIE " died\n"
# define NEED_EAT 0
# define NEED_SLEEP 1
# define NEED_THINK 2
# define DEAD 3

typedef struct		s_tvar
{
	int				alive;
	int				nb_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				nb_eat;
	int				*tab_eat;
	int				*forks;
	pthread_mutex_t	mutex_forks;
	struct timeval	initial_time;
}					t_tvar;

typedef struct		s_thread
{
	struct timeval	now;
	struct timeval	last_eat;
	int				num_philo;
	int				state;
	t_tvar			*var;
}					t_thread;

void				*philosophers(void *data);
int					init_struct(t_thread **thread, t_tvar **var, int argc,
	char **argv);
int					diff_time_ms(struct timeval first, struct timeval second);
void				ft_putnbr_fd(int n, int fd);
int					ft_strlen(const char *s);
void				write_status(t_thread *thread, char *action);
int					ft_atoi(const char *nptr);
int					nb_eat(int *tab_eat, int nb_eat, int nb_philo);
int					free_ret(void *one, void *two, void *three, void *four);
void				sleep_think(t_thread *thread);
int					check_philo(t_thread *thread);
void				eat(t_thread *thread);
int					eating(t_thread *thread);

#endif
