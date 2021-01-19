/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:32:54 by yvanat            #+#    #+#             */
/*   Updated: 2021/01/19 17:18:25 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	end(t_thread *thread)
{
	int	i;

	i = -1;
	while (++i < thread->var->nb_philo)
		kill(thread[i].pid, SIGKILL);
	sem_close(thread->var->forks);
	sem_unlink("forks");
	sem_close(thread->var->status);
	sem_unlink("status");
	sem_close(thread->var->alive);
	sem_unlink("alive");
	sem_close(thread->var->tab_eat);
	sem_unlink("tab_eat");
	free_ret(thread->var, thread, NULL, NULL);
}

int		init_struct(t_thread **thread, t_tvar **var,
	int argc, char **argv)
{
	if (!(*thread = malloc(sizeof(t_thread) * ft_atoi(argv[1]))))
		return (-1);
	if (!(*var = malloc(sizeof(t_tvar))))
		return (free_ret(*thread, NULL, NULL, NULL));
	init_struct_var(argc, argv, var);
	if (!((*var)->tab_eat = malloc(sizeof(int) * ft_atoi(argv[1]))))
		return (free_ret(*thread, *var, NULL, NULL));
	sem_unlink("forks");
	if (!((*var)->forks = sem_open("forks", O_CREAT, 0, (*var)->nb_philo)))
		return (free_ret(*thread, (*var)->tab_eat, *var, NULL));
	sem_unlink("status");
	if (!((*var)->status = sem_open("status", O_CREAT, 0, 1)))
	{
		sem_close((*var)->forks);
		sem_unlink("forks");
		return (free_ret(*thread, (*var)->tab_eat, *var, NULL));
	}
	return (create_sem(thread, var));
}

void	init_struct_var(int argc, char **argv, t_tvar **var)
{
	(*var)->nb_philo = ft_atoi(argv[1]);
	(*var)->t_die = ft_atoi(argv[2]);
	(*var)->t_eat = ft_atoi(argv[3]);
	(*var)->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		(*var)->nb_eat = ft_atoi(argv[5]);
	else
		(*var)->nb_eat = -1;
}

int		create_sem(t_thread **thread, t_tvar **var)
{
	sem_unlink("alive");
	if (!((*var)->alive = sem_open("alive", O_CREAT, 0, 0)))
	{
		sem_close((*var)->forks);
		sem_unlink("forks");
		sem_close((*var)->status);
		sem_unlink("status");
		return (free_ret(*thread, (*var)->tab_eat, *var, NULL));
	}
	sem_unlink("tab_eat");
	if (!((*var)->tab_eat = sem_open("tab_eat", O_CREAT, 0, 0)))
	{
		sem_close((*var)->forks);
		sem_unlink("forks");
		sem_close((*var)->status);
		sem_unlink("status");
		sem_close((*var)->alive);
		sem_unlink("alive");
		return (free_ret(*thread, (*var)->tab_eat, *var, NULL));
	}
	return (0);
}
