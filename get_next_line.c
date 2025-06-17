/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 10:28:15 by texenber          #+#    #+#             */
/*   Updated: 2025/06/17 14:09:39 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_from_file(int fd)
{
	char		*buffer;
	int			bytes_read;

	buffer = malloc (3 + 1 * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, 3);
	if (bytes_read <= 0)
		return (free (buffer), NULL);
	buffer[3 + 1] = '\0';
	return (buffer);
}

char	*get_next_line(int fd)
{
	char	*bigger_buffer;

	bigger_buffer = read_from_file(fd);
	return (bigger_buffer);
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
