/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-han <moel-han@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:40:53 by moel-han          #+#    #+#             */
/*   Updated: 2025/11/06 16:01:17 by moel-han         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>

void ft_bezro(void *s, size_t n);
void *ft_calloc(size_t nmemb, size_t size);
size_t ft_strlen(char const *str);
char *ft_strchr(const char *s, int c);
char *ft_strjoin(char const *s1, char const *s2);
void *ft_memcpy(void *dest, const void *src, size_t n);
char *ft_strdup(const char *src);
char	*get_next_line(int fd);

#endif