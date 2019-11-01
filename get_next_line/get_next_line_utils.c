/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:20:52 by yvanat            #+#    #+#             */
/*   Updated: 2019/11/01 19:10:20 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strjoin(char **line, char *buffer, int i, int index)
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
	while (buffer[k + index] && buffer[k + index] != '\n')
	{
		new_line[j + k] = buffer[k + index];
		k++;
	}
	new_line[j + k] = '\0';
	free(*line);
	*line = new_line;
	return (1);
}

int	read_from_index(char **line, char *buffer, int index, int fd)
{
	static ssize_t	size = 0;
	int				i;

	if (!(*line = malloc(1)))
		return (-1);
	(*line)[0] = '\0';
	while (1)
	{
		if (index == 0 || index == -2)
		{
			size = read(fd, buffer, BUFFER_SIZE);
			if (index == -2 && size == 0)
				return (-2);
			if (index == -2)
				index = 0;
			if (size == -1 || size == 0)
				return ((int)size);
			buffer[size] = '\0';
		}
		i = 0;
		while (buffer[index + i] && buffer[index + i] != '\n')
			i++;
		if (!(ft_strjoin(line, buffer, i, index)))
			return (-1);
		if (size == 0 || buffer[index + i] == '\n')
			return ((size == 0) ? 0 : index + i + 1);
		index = -2;
	}
	return (-1);
}
