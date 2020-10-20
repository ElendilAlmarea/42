/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrunel <mbrunel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 19:28:15 by mbrunel           #+#    #+#             */
/*   Updated: 2020/03/02 17:55:38 by mbrunel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	reset_std(int in, int out)
{
	dup2(in, STDIN_FILENO);
	close(in);
	dup2(out, STDOUT_FILENO);
	close(out);
}

void	set_std(t_args *arg)
{
	if (arg->in != STDIN_FILENO)
	{
		dup2(arg->in, STDIN_FILENO);
		close(arg->in);
	}
	if (arg->out != STDOUT_FILENO)
	{
		dup2(arg->out, STDOUT_FILENO);
		close(arg->out);
	}
}

void	save_std(int *in, int *out)
{
	*in = dup(STDIN_FILENO);
	*out = dup(STDOUT_FILENO);
}
