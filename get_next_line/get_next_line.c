/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:17:13 by yvanat            #+#    #+#             */
/*   Updated: 2019/11/01 19:11:39 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char		*buffer;
	static int		index = 0;

	if (!line)
		return (-1);
	if (!buffer)
		buffer = malloc(BUFFER_SIZE + 1);
	if (index == -2)
	{
		if (buffer)
			free(buffer);
		if (!(*line = malloc(1)))
			return (-1);
		buffer = NULL;
		return (0);
	}
	index = read_from_index(line, buffer, index, fd);
	if (index == -1)
	{
		if (buffer)
			free(buffer);
		buffer = NULL;
		index = 0;
		return (-1);
	}
	else if (index == 0)
	{
		if (buffer)
			free(buffer);
		buffer = NULL;
		return (0);
	}
	else
		return (1);
}
