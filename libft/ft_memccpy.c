/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:43:49 by yvanat            #+#    #+#             */
/*   Updated: 2019/10/20 11:05:23 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char	*b;
	char	*s;

	i = 0;
	b = (char*)dest;
	s = (char*)src;
	while (i < n)
	{
		b[i] = s[i];
		if (s[i] == (char)c)
			break ;
		i++;
	}
	if (i == n)
		return (NULL);
	return (dest + i + 1);
}
