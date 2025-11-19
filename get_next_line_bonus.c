/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moel-han <moel-han@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 16:14:05 by moel-han          #+#    #+#             */
/*   Updated: 2025/11/19 19:17:24 by moel-han         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char *buffer, char *buff)
{
	char	*tmp;

	if (!buffer)
		return (ft_strdup(buff));
	tmp = ft_strjoin(buffer, buff);
	free(buffer);
	return (tmp);
}

char	*extract_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
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
	return (line);
}

char	*next_line(char *buffer)
{
	int		i;
	int		j;
	char	*next;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	next = ft_calloc(ft_strlen(buffer) - i, sizeof(char));
	if (!next)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		next[j++] = buffer[i++];
	free(buffer);
	return (next);
}

char	*read_and_buffer(int fd, char *res)
{
	char	*buffer;
	int		read_byte;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	read_byte = 1;
	while (read_byte > 0)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_byte] = '\0';
		res = ft_free(res, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || MAX_FD <= fd)
		return (NULL);
	buffer[fd] = read_and_buffer(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = extract_line(buffer[fd]);
	buffer[fd] = next_line(buffer[fd]);
	return (line);
}

// int main(void)
// {
// 	int fd1;
// 	int fd2;
// 	int fd3;

// 	char *line1;
// 	char *line2;
// 	char *line3;

// 	fd1 = open("file1.txt", O_RDONLY);
// 	fd2 = open("file2.txt", O_RDONLY);
// 	fd3 = open("file3.txt", O_RDONLY);

// 	if (fd1 == -1 || fd2 == -1 || fd1 == -1)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}

// 	line1 = get_next_line(fd1);
// 	printf("Line1 fd  %s", line1);
// 	free(line1);

// 	line2 = get_next_line(fd2);
// 	printf("\nLine2 fd  %s", line2);
// 	free(line2);

// 	line3 = get_next_line(fd3);
// 	printf("\nLine3 fd  %s", line3);
// 	free(line3);
// 	printf("---------------------------------------\n");

// 	line1 = get_next_line(fd1);
// 	printf("Line1 fd  %s", line1);
// 	free(line1);

// 	line2 = get_next_line(fd2);
// 	printf("\nLine2 fd  %s", line2);
// 	free(line2);

// 	line3 = get_next_line(fd3);
// 	printf("\nLine3 fd  %s", line3);
// 	free(line3);

// 	close(fd1);
// 	return (0);
// }
