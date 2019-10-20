/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:28:57 by yvanat            #+#    #+#             */
/*   Updated: 2019/10/20 11:44:04 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	l;
	char	*bb;

	i = 0;
	l = 0;
	bb = (char*)big;
	if (little[0] == 0)
		return (bb);
	while (little[l])
		l++;
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j] == big[i + j] && (i + j) < len)
		{
			if (j++ == (l - 1))
				return (bb + i);
		}
		i++;
	}
	return (NULL);
}
