/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 01:24:23 by mbrunel           #+#    #+#             */
/*   Updated: 2020/03/08 03:47:02 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			aff_env(char *env[])
{
	int i;

	i = -1;
	while (!env[++i])
		;
	i--;
	while (env[++i])
		ft_printf("%s\n", env[i]);
	return (0);
}

int			aff_pwd(void)
{
	char *str;

	str = pwd();
	if (!str)
		return (-1);
	ft_printf("%s\n", str);
	free(str);
	return (0);
}

int			echo(t_lst *lst)
{
	char *option;

	if (!lst)
	{
		ft_putstr("\n");
		return (0);
	}
	if (ft_strcmp(lst->text, "-n"))
		option = "\n";
	else
	{
		option = "\0";
		lst = lst->next;
	}
	while (lst)
	{
		ft_putstr(lst->text);
		lst = lst->next;
	}
	ft_putstr(option);
	return (1);
}

void		bye(int rt)
{
	ft_printf("%sBye%s\n", GREEN, NONE);
	exit(rt);
}
