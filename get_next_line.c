/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 10:28:15 by texenber          #+#    #+#             */
/*   Updated: 2025/06/25 07:47:14 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*set_line(char *line)
{
	char	*tmp;
	size_t	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || line[i + 1] == '\0')
		return (NULL);
	tmp = ft_substr(line, (i + 1), (ft_strlen(line) - (i + 1)));
	if (!tmp)
		return (NULL);
	line[i + 1] = '\0';
	return (tmp);
}

static char	*read_from_file(int fd, char *leftover, char *buffer)
{
	char		*tmp;
	ssize_t		bytes_read;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(leftover), NULL);
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!leftover)
			leftover = ft_strdup("");
		tmp = leftover;
		leftover = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (!leftover)
			return (NULL);
		if (ft_strchr(leftover, '\n'))
			break ;
	}
	return (leftover);
}

char	*get_next_line(int fd)
{
	static char	*leftover = NULL;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(leftover), leftover = NULL, NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free(leftover), leftover = NULL, NULL);
	line = read_from_file(fd, leftover, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (free (line), NULL);
	leftover = set_line(line);
	if (!leftover)
		free (leftover);
	return (line);
}
