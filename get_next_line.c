/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-han <moel-han@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:09:07 by moel-han          #+#    #+#             */
/*   Updated: 2025/11/26 18:12:50 by moel-han         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buffer, char *buff)
{
	char	*tmp;

	if (!buffer)
		return (ft_strdup(buff));
	tmp = ft_strjoin(buffer, buff);
	free(buffer);
	if (!tmp)
		return (NULL);
	return (tmp);
}

char	*extract_line(char *buffer)
{
	int		i;
	char	*line;

	if (!buffer || !buffer[0])
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc((i + 2) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*next_line(char *buffer)
{
	int		i;
	int		j;
	char	*next;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	i++;
	next = malloc((ft_strlen(buffer) - i + 1) * sizeof(char));
	if (!next)
		return (NULL);
	j = 0;
	while (buffer[i])
		next[j++] = buffer[i++];
	free(buffer);
	next[j] = '\0';
	return (next);
}

char	*read_and_buffer(int fd, char *res)
{
	char	*buffer;
	int		read_byte;

	buffer = malloc(((size_t)BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	read_byte = 1;
	while (!ft_strchr(res, '\n') && read_byte > 0)
	{
		read_byte = read(fd, buffer, (size_t)BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_byte] = '\0';
		res = ft_free(res, buffer);
		if (!res)
		{
			free(buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_and_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = extract_line(buffer);
	buffer = next_line(buffer);
	return (line);
}
