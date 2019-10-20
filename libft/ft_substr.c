/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 17:29:28 by yvanat            #+#    #+#             */
/*   Updated: 2019/10/20 18:36:59 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*new;

	if (!s || start > ft_strlen(s))
	{
		if (!(new = malloc(1)))
			return (NULL);
		new[0] = '\0';
		return (new);
	}
	i = 0;
	while ((i < len) && s[start + i])
		i++;
	if (!(new = malloc(sizeof(*new) * (i + 1))))
		return (NULL);
	i = 0;
	while ((i < len) && s[start + i])
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
