/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:49:01 by yvanat            #+#    #+#             */
/*   Updated: 2019/10/17 12:44:34 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strncpy(char *dest, const char *src, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = 0;
}

static int	count_str(const char *s, char c, int *v, int *vv)
{
	int	i;
	int	j;

	*v = 0;
	*vv = 0;
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i == 0)
		{
			while (s[i] == c)
				i++;
			if (i > 0)
				i--;
		}
		if (i != 0 && s[i] == c && s[i - 1] != c)
			j++;
		i++;
	}
	if ((j == 0 && !s[0]) || s[i - 1] == c)
		return (j + 1);
	return (j + 2);
}

static char	**ft_free(char **tab, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static char	**ret_tab(char **tab, int index)
{
	if (!(tab[index] = malloc(sizeof(NULL))))
		return (ft_free(tab, index));
	tab[index] = NULL;
	return (tab);
}

char		**ft_split(const char *s, char c)
{
	char	**tab;
	int		var[4];

	if (!s)
		return (NULL);
	var[3] = count_str(s, c, &var[0], &var[2]);
	if (!(tab = malloc(sizeof(*tab) * var[3])))
		return (NULL);
	while (s[var[2]] == c)
		var[2]++;
	while (var[0] < var[3] - 1)
	{
		var[1] = 0;
		while (s[var[2]] != c && s[var[2]])
			if (var[2]++ + var[1]++ < -2147483648)
				var[2] += 0;
		if (!(tab[var[0]] = malloc(sizeof(**tab) * (var[1] + 1))))
			return (ft_free(tab, var[0]));
		ft_strncpy(tab[var[0]], s + var[2] - var[1], var[1]);
		while (s[var[2]] == c)
			var[2]++;
		var[0]++;
	}
	return (ret_tab(tab, var[0]));
}
