/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:43:36 by yvanat            #+#    #+#             */
/*   Updated: 2019/10/20 17:26:25 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(const char *s1, const char *set)
{
	char	*new;
	int		i;
	int		j;
	int		len;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	len = (int)ft_strlen(s1) - 1;
	if (len < 0)
		len = 0;
	while (len >= 0 && ft_strchr(set, s1[len]))
		len--;
	len = (i > len) ? 0 : (len - i + 1);
	if (!(new = malloc(sizeof(*new) * (len + 1))))
		return (NULL);
	j = 0;
	while (len-- > 0 && j++ >= 0)
		new[j - 1] = s1[i + j - 1];
	new[j] = '\0';
	return (new);
}
