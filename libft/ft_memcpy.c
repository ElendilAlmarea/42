/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:37:34 by yvanat            #+#    #+#             */
/*   Updated: 2019/10/20 11:13:44 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*c;
	char	*s;

	if (!dest && !src)
		return (NULL);
	i = 0;
	c = (char*)dest;
	s = (char*)src;
	while (i < n)
	{
		c[i] = s[i];
		i++;
	}
	return (dest);
}
