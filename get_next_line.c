/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 10:28:15 by texenber          #+#    #+#             */
/*   Updated: 2025/06/21 13:07:44 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

obtained_remaining // this function is meant to take anything after the '\n' and store it into the bigge						r_buffer.
extract_line // this function is meant to take everything before a '\n' and put it in the line string.
static char	*append_buffer(char *bigger_buffer, char *buffer)
{
	char	*tmp;

	tmp = ft_strjoin(bigger_buffer, buffer);
	return (free (bigger_buffer), tmp);
}

static char	*read_from_file(char *bigger_buffer, int fd)
{
	char		*buffer;
	int			bytes_read;

	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), NULL);
		buffer[bytes_read] = '\0';
		bigger_buffer = append_buffer(bigger_buffer, buffer);
		if (ft_strchr(bigger_buffer, '\n'))
			break;
	}
	free (buffer);
	return (bigger_buffer);
}

char	*get_next_line(int fd)
{
	static char	*bigger_buffer;
	char 		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!bigger_buffer)
		bigger_buffer = malloc(1 * sizeof(char));
	if (!ft_strchr(bigger_buffer, '\n'))
		bigger_buffer = read_from_file(bigger_buffer, fd);
	if (!bigger_buffer)
		return (free(bigger_buffer), NULL);
	line = extract_line(bigger_buffer);
	bigger_buffer = obtain_remaining(bigger_buffer);
	return (line);
}

#include <stdio.h>
int	main(void)
{
	int	fd;
	char	*next_line;
	int	count;

	count = 0;
	fd = open("example.txt", O_RDONLY);
	if (fd == -1)
		return (printf ("Error opening file"), 1);
	while (1)
	{
		next_line = get_next_line(fd);
		if (next_line == NULL)
			break;
		count++;
		printf("[%d]:%s\n", count, next_line);
		free (next_line);
		next_line = NULL;
	}
	close(fd);
	return(0);
}
