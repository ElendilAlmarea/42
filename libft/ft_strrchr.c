/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:31:23 by yvanat            #+#    #+#             */
/*   Updated: 2019/10/20 11:44:33 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*a;

	i = 0;
	a = (char*)s;
	while (s[i])
		i++;
	while (i >= 0 && s[i] != c)
		i--;
	if (i < 0)
		return (NULL);
	return (a + i);
}
