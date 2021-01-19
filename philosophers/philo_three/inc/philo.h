/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:46:17 by yvanat            #+#    #+#             */
/*   Updated: 2021/01/19 17:18:42 by yvanat           ###   ########.fr       */
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
# include <semaphore.h>
# include <fcntl.h>
# include <sys/types.h>
# include <signal.h>

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
	int				nb_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				nb_eat;
	sem_t			*alive;
	sem_t			*tab_eat;
	sem_t			*forks;
	sem_t			*status;
	struct timeval	initial_time;
}					t_tvar;

typedef struct		s_thread
{
	struct timeval	now;
	struct timeval	last_eat;
	int				num_philo;
	int				state;
	pid_t			pid;
	t_tvar			*var;
}					t_thread;

void				*philosophers(void *data);
void				*wait_alive(void *data);
void				*wait_tab_eat(void *data);
int					init_struct(t_thread **thread, t_tvar **var, int argc,
	char **argv);
void				init_struct_var(int argc, char **argv, t_tvar **var);
int					create_sem(t_thread **thread, t_tvar **var);
void				end(t_thread *thread);
int					diff_time_ms(struct timeval first, struct timeval second);
void				ft_putnbr_fd(int n, int fd);
int					ft_strlen(const char *s);
void				write_status(t_thread *thread, char *action);
int					ft_atoi(const char *nptr);
int					free_ret(void *one, void *two, void *three, void *four);
void				sleep_think(t_thread *thread);
int					check_philo(t_thread *thread);
void				eat(t_thread *thread);
int					eating(t_thread *thread);

#endif
