/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlaforge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:13:21 by rlaforge          #+#    #+#             */
/*   Updated: 2022/05/02 14:39:13 by rlaforge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stddef.h>
#include<stdlib.h>
#include"get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i++])
		;
	return (--i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*buf;
	unsigned int	i;
	size_t			x;

	i = 0;
	if (s == 0)
		return (NULL);
	x = ft_strlen(s);
	if (start >= x)
	{
		buf = malloc(sizeof(char));
		if (!buf)
			return (NULL);
		*buf = '\0';
		return (buf);
	}
	if (len >= x)
		len = x - start;
	buf = malloc(sizeof(char) * (len + 1));
	if (!buf)
		return (NULL);
	while (len-- && (start + len) <= x)
		buf[i++] = s[start++];
	buf[i] = '\0';
	return (buf);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	int		longueur;

	if (!s1 || !s2)
		return (NULL);
	longueur = ft_strlen(s1) + ft_strlen(s2) + 1;
	tab = malloc(sizeof(char) * longueur);
	if (!tab)
		return (NULL);
	ft_strlcpy(tab, s1, longueur);
	ft_strlcat(tab, s2, longueur);
	return (tab);
}

int	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dl;
	size_t	sl;
	size_t	i;

	dl = ft_strlen(dst);
	sl = ft_strlen(src);
	i = 0;
	if (size == 0 || dl > size)
		return ((int)size + sl);
	if (!*src)
		return ((int)dl);
	while (src[i] && (dl + i) < size - 1)
	{
		dst[dl + i] = src[i];
		i++;
	}
	dst[dl + i] = '\0';
	return ((int)dl + sl);
}

int	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		i;
	char	*str;

	i = 0;
	str = (char *)src;
	if (!size)
		return ((int)ft_strlen(src));
	while (str[i] && i < size - 1)
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return ((int)ft_strlen(src));
}
