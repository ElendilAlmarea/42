/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:37:02 by yvanat            #+#    #+#             */
/*   Updated: 2019/10/20 18:07:31 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*c;
	char	*s;

	if (!dest && !src)
		return (NULL);
	i = 0;
	c = (char*)dest;
	s = (char*)src;
	if (dest < src)
		while (i++ < n)
			c[i - 1] = s[i - 1];
	else if (dest > src)
		while (i++ < n)
			c[n - i] = s[n - i];
	return (dest);
}
