/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:36:33 by yvanat            #+#    #+#             */
/*   Updated: 2019/10/20 11:06:33 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*b;
	void	*x;

	i = 0;
	b = (char*)s;
	x = (void*)s;
	while (i < n && b[i] != (char)c)
		i++;
	if (i == n)
		return (NULL);
	return (x + i);
}
