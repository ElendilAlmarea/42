/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:05:52 by yvanat            #+#    #+#             */
/*   Updated: 2019/10/12 15:55:28 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len_tot;
	size_t	i;
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	len_tot = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(new = malloc(sizeof(*new) * len_tot)))
		return (NULL);
	i = 0;
	len_tot = 0;
	while (s1[i])
		new[len_tot++] = s1[i++];
	i = 0;
	while (s2[i])
		new[len_tot++] = s2[i++];
	new[len_tot] = 0;
	return (new);
}
