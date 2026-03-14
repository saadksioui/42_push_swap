/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sksioui <sksioui@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 01:36:08 by sksioui           #+#    #+#             */
/*   Updated: 2025/12/24 09:29:30 by sksioui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*line_clip(char **rest)
{
	char	*line;
	char	*newline_pos;
	char	*leftovers;

	newline_pos = ft_strchr(*rest, '\n');
	if (newline_pos)
	{
		line = ft_substr(*rest, 0, newline_pos - *rest + 1);
		leftovers = ft_strdup(newline_pos + 1);
		free(*rest);
	}
	else
	{
		line = ft_strdup(*rest);
		free(*rest);
		leftovers = NULL;
	}
	*rest = leftovers;
	return (line);
}

int	read_join(int fd, char **rest)
{
	char	*buffer;
	ssize_t	bytes_read;

	if (BUFFER_SIZE <= 0)
		return (-1);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(buffer);
		return (bytes_read);
	}
	buffer[bytes_read] = '\0';
	*rest = ft_strjoin(*rest, buffer);
	free(buffer);
	if (!*rest)
		return (-1);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	int			result;

	if (fd < 0)
		return (NULL);
	while (!rest || !ft_strchr(rest, '\n'))
	{
		result = read_join(fd, &rest);
		if (result < 0)
			return (NULL);
		if (result == 0)
			break ;
	}
	if (!rest || rest[0] == '\0')
		return (free(rest), rest = NULL, NULL);
	return (line_clip(&rest));
}
