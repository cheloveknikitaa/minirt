/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caugusta <caugusta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:03:35 by caugusta          #+#    #+#             */
/*   Updated: 2021/05/10 15:59:18 by caugusta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	free_all(char **line, char *buf, char **keepread, int i)
{
	if (*line != NULL && i == -1)
	{
		free(*line);
		*line = NULL;
	}
	if (buf != NULL)
	{
		free(buf);
		buf = NULL;
	}
	if (*keepread != NULL && i < 1)
	{
		free(*keepread);
		*keepread = NULL;
	}
	return (i);
}

static int	find_n(char **line, char **keepread)
{
	char	*buf;

	buf = ft_strchr(*keepread, '\n');
	if (buf != NULL)
	{
		*buf = '\0';
		*line = ft_strdup(*keepread);
		buf = ft_strdup(buf + 1);
		if (*line == NULL || buf == NULL)
			return (free_all(line, buf, keepread, -1));
		free(*keepread);
		*keepread = buf;
		return (1);
	}
	return (0);
}

static int	read_n_find(int fd, char *buffer_read, char **line, char **keepread)
{
	size_t	read_byte;

	read_byte = read(fd, buffer_read, BUFFER_SIZE);
	while (read_byte)
	{
		buffer_read[read_byte] = '\0';
		*keepread = ft_strjoin_gnl(*keepread, buffer_read);
		if (keepread == NULL)
			return (free_all(line, buffer_read, keepread, -1));
		if (find_n(line, keepread) == 1)
			return (free_all(line, buffer_read, keepread, 1));
		else if (find_n(line, keepread) == -1)
			return (free_all(line, buffer_read, keepread, -1));
		read_byte = read(fd, buffer_read, BUFFER_SIZE);
	}
	free(buffer_read);
	buffer_read = NULL;
	if (find_n(line, keepread) == 1)
		return (1);
	*line = ft_strdup(*keepread);
	if (*line == NULL)
		return (free_all(line, buffer_read, keepread, -1));
	return (free_all(line, buffer_read, keepread, 0));
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	size_t	size;
	char	*join;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = malloc(size);
	if (join == NULL)
		return (NULL);
	join[size - 1] = '\0';
	ft_memcpy(join, s1, ft_strlen(s1));
	ft_memcpy(join + ft_strlen(s1), s2, ft_strlen(s2));
	free (s1);
	s1 = NULL;
	return (join);
}

int	get_next_line(int fd, char **line)
{
	static char	*keepread;
	char		*buffer_read;
	int			result;

	if (BUFFER_SIZE < 1 || !line || fd < 0 || read(fd, 0, 0) < 0)
		return (-1);
	buffer_read = malloc(BUFFER_SIZE + 1);
	if (buffer_read == NULL)
		return (-1);
	if (keepread == NULL)
	{
		keepread = ft_strdup("");
		if (keepread == NULL)
		{
			free(buffer_read);
			buffer_read = NULL;
			return (-1);
		}
	}
	result = read_n_find(fd, buffer_read, line, &keepread);
	return (result);
}
