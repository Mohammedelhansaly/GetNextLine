/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-han <moel-han@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:40:44 by moel-han          #+#    #+#             */
/*   Updated: 2025/11/12 19:11:44 by moel-han         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bouns.h"

void ft_bezro(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

void *ft_calloc(size_t nmemb, size_t size)
{
	char *str;

	if (size != 0 && nmemb > SIZE_MAX / size)
	{
		return NULL;
	}
	str = malloc(nmemb * size);
	if (!str)
	{
		return NULL;
	}
	ft_bezro(str, (nmemb * size));
	return str;
}
size_t ft_strlen(char const *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return i;
}

char *ft_strjoin(char const *s1, char const *s2)
{
	char *new;
	int i;
	int j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	new = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

char *ft_strchr(const char *s, int c)
{
	while ((char)c != *s)
	{
		if (!*s)
			return (0);
		s++;
	}
	return ((char *)s);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	if (dest != src)
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dest);
}
char	*ft_strdup(const char *src)
{
	size_t	size;
	char	*dest;

	size = ft_strlen(src);
	dest = (char *)malloc(size * sizeof(char) + 1);
	if (dest == NULL)
		return (0);
	ft_memcpy(dest, src, size);
	dest[size] = '\0';
	return (dest);
}


