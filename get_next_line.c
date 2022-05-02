/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlaforge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:11:59 by rlaforge          #+#    #+#             */
/*   Updated: 2022/05/02 16:13:10 by rlaforge         ###   ########.fr       */
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

char	*ft_read(char *str, int fd)
{
	char	*buff;

	buff = malloc(sizeof(char) * BUFFER_SIZE);
	if(!read(fd, str, BUFFER_SIZE) || !buff)
		return (free(buff), free(str), NULL);
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
	char 		*line;

	str = malloc(sizeof(char) * BUFFER_SIZE);
	if (!str)
		return (free(str), NULL);
	str = ft_read(str, fd);
	if (!str)
		return (free(str), NULL);
	if (save && str)
		str = ft_strjoin(save, str);
	save = ft_substr(str, ft_has_backslash_n(str), ft_strlen(str));
	line = ft_substr(str, 0, ft_has_backslash_n(str));
	free(str);
	return (line);
}

/*
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
*/
