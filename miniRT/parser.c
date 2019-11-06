/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:32:18 by yvanat            #+#    #+#             */
/*   Updated: 2019/11/06 19:12:30 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		parse_call(t_data *data, char *buffer, int i)
{
	if (buffer[i] == 'R')
		return (parse_r(data, buffer, i));
	if (buffer[i] == 'A')
		return (parse_a(data, buffer, i));
	if (buffer[i] == 'c')
		return (parse_c(data, buffer, i));
	if (buffer[i] == 'l')
		return (parse_l(data, buffer, i));
	if (buffer[i] == 'p' && buffer[i] == 'l')
		return (parse_pl(data, buffer, i));
	if (buffer[i] == 's' && buffer[i] == 'p')
		return (parse_sp(data, buffer, i));
	if (buffer[i] == 's' && buffer[i] == 'q')
		return (parse_sq(data, buffer, i));
	if (buffer[i] == 'c' && buffer[i] == 'y')
		return (parse_cy(data, buffer, i));
	if (buffer[i] == 't' && buffer[i] == 'r')
		return (parse_tr(data, buffer, i));
	put_error(1);
	free(buffer);
	ft_free(data);
	return (0);
}

void	ft_parse(char *file, t_data *data)
{
	char	*buffer;
	ssize_t	size;
	int		i;

	if (!(buffer = malloc(10001)))
		ft_free(data);
	if ((size = read(open(file, O_RDONLY), buffer, 10000)) > 0)
	{
		put_error(size);
		free(buffer);
		ft_free(data);
	}
	buffer[size] = '\0';
	i = -1;
	while (buffer[++i] != '\0')
		i = parse_call(data, buffer, i);
	free(buffer);
}
