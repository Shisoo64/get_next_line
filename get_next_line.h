/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlaforge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:14:05 by rlaforge          #+#    #+#             */
/*   Updated: 2022/05/02 15:18:44 by rlaforge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include<sys/types.h>
#include<sys/stat.h>
#include <fcntl.h> 

char	*get_next_line(int fd);
int	ft_strlen(const char *s);
int	ft_strlen_n(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char const *s2);
int	ft_strlcat(char *dst, const char *src, size_t size);
int	ft_strlcpy(char *dst, const char *src, size_t size);

#endif
