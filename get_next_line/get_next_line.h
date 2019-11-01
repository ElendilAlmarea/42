/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:17:42 by yvanat            #+#    #+#             */
/*   Updated: 2019/11/01 13:06:54 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

int	get_next_line(int fd, char **line);
int	read_from_index(char **line, char *buffer, int index, int fd);
int	ft_strlen(char *s);
int	ft_strjoin(char **line, char *buffer, int i, int index);

#endif
