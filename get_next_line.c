/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlaforge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:11:59 by rlaforge          #+#    #+#             */
/*   Updated: 2022/05/02 14:32:12 by rlaforge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stddef.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include"get_next_line.h"

int	ft_has_backslash_n(char *s)
{
	int	i;

	i = -1;
	if (!s)
		return (0);
	while (s[++i])
		if (s[i] == '\n')
			return (i + 1);
	return (0);
}

char	*ft_read(char *str, char *buff, int fd)
{
	if(!read(fd, str, BUFFER_SIZE))
		return (malloc(1));
	if (!ft_has_backslash_n(str))
		while (!ft_has_backslash_n(buff) && read(fd, buff, BUFFER_SIZE))
				str = ft_strjoin(str, buff);
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char 		*str;
	char 		*buff;
	char 		*line;

	str = malloc(sizeof(char) * BUFFER_SIZE + 1);
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	str = ft_read(str, buff, fd);
	if (save && str)
		str = ft_strjoin(save, str);
	save = ft_substr(str, ft_has_backslash_n(str), ft_strlen(str));
	line = ft_substr(str, 0, ft_has_backslash_n(str));
	return (line);
}

int main(void)
{
    int fd;

    fd = open("test", O_RDONLY);
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
}
