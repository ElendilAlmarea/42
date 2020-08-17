/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvanat <yvanat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:39:15 by yvanat            #+#    #+#             */
/*   Updated: 2020/08/17 19:22:29 by yvanat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <libc.h>
#include <unistd.h>
#include <errno.h>

int		ft_strlen(char *str);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_write(int fd, const void *content, size_t length);
int		ft_read(int fd, void *buffer, size_t length);
char	*ft_strdup(const char*src);

int		main(void)
{
	ssize_t	size;
	char	cpy[18];
	char	buffer[1000];

	printf("\nTests libasm\n\n");
	if (ft_write(1, "Test de ft_write\n\n", 18) == -1)
		perror("write");
	printf("Test de ft_strcmp memes chaines : %d, et chaines differentes : %d\n",
			ft_strcmp("test", "test"), ft_strcmp("test1", "test2"));
	printf("Test de strcmp memes chaines : %d, et chaines differentes : %d\n\n",
			strcmp("test", "test"), strcmp("test1", "test2"));
	printf("%s\n\n", ft_strcpy(cpy, "Test de ft_strcpy"));
	printf("Test de ft_strlen : %d\nTest de strlen : %ld\n\n", ft_strlen(cpy), strlen(cpy));
	printf("%s\n\n", ft_strdup("Test de ft_strdup"));
	printf("Test de ft_read sur l entree standard :\n");
	size = read(0, buffer, 999);
	if (size > 0)
		buffer[(int)size] = '\0';
	if (size == -1)
		perror("read");
	write(1, buffer, size);
	return (0);
}

