/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:17:13 by yvanat            #+#    #+#             */
/*   Updated: 2019/10/20 15:23:50 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char		buffer[BUFFER_SIZE];
	static int		index = 0;

	if (!line)
		return (-1);
	index = read_from_index(line, buffer, index, fd);
	if (index == -1)
	{
		index = 0;
		return (-1);
	}
	else if (index == 0)
		return (0);
	else
		return (1);
}

int		read_from_index(char **line, char *buffer, int index, int fd)
{
	int				i;
	int				j;
	int				k;
	static ssize_t	size;
	char			*tmp;

	if (index == 0)
		size = read(fd, buffer, BUFFER_SIZE);
	if (size == -1)
		return (-1);
	k = 1;
	while (k++)
	{
		i = 0;
		j = -1;
		if (size == 0)
		{
			while (buffer[index + i] != '\n' && buffer[index + i] != -1)
				i++;
			if (!(*line) || ft_strlen(*line) < i)
			{
				if (*line)
					free(*line);
				if (!(*line = malloc(i + 1)))
					return (-1);
			}
			while (++j < i)
				(*line)[j] = buffer[index + j];
			(*line)[j] = '\0';
			return ((buffer[index + i] == -1) ? 0 : 1)
		}
		else
		{
			while (buffer[index + i] != '\n' && index + i < (int)size)
				i++;
		}
	}
}
