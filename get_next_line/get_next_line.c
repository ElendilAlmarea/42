/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:17:13 by yvanat            #+#    #+#             */
/*   Updated: 2019/10/30 15:15:57 by yvanat           ###   ########.fr       */
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
	index = read_from_index(line, buffer, index, fd);
	if (index == -1)
	{
		//if (buffer)
		//	free(buffer);
		buffer = NULL;
		index = 0;
		return (-1);
	}
	else if (index == 0)
	{
		//if (buffer)
		//	free(buffer);
		buffer = NULL;
		return (0);
	}
	else
		return (1);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strjoin(char **line, char *buffer, int i)
{
	char	*new_line;
	int		j;
	int		k;

	if (!(new_line = malloc(ft_strlen(*line) + i + 1)))
		return (0);
	j = -1;
	while ((*line)[++j])
		new_line[j] = (*line)[j];
	k = 0;
	while (buffer[k] && buffer[k] != '\n')
	{
		new_line[j + k] = buffer[k];
		k++;
	}
	new_line[j + k] = '\0';
	free(*line);
	*line = malloc(ft_strlen(new_line) + 1);
	j = -1;
	while (new_line[++j])
		(*line)[j] = new_line[j];
	(*line)[j] = '\0';
	free(new_line);
	return (1);
}

int	read_from_index(char **line, char *buffer, int index, int fd)
{
	ssize_t	size;
	int		i;

	if (!(*line = malloc(1)))
		return (-1);
	(*line)[0] = '\0';
	while (1)
	{
		if (index == 0)
		{
			size = read(fd, buffer, BUFFER_SIZE);
			if (size == -1 || size == 0)
				return (size);
			buffer[size] = '\0';
		}
		i = 0;
		while (buffer[index + i] && buffer[index + i] != '\n')
			i++;
		if (!(ft_strjoin(line, buffer, i)))
			return (-1);
		if (size == 0 || buffer[index + i] == '\n')
			return ((size == 0) ? 0 : index + i + 1);
		index = 0;
	}
	return (-1);
}
