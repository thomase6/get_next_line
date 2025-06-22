/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 11:21:52 by texenber          #+#    #+#             */
/*   Updated: 2025/06/22 11:43:48 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	int 	fd;
	char    *next_line;
	int 	count;
	
	if (argc != 2)
		return (1);
	count = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (printf ("Error opening file"), 1);
	while (1)
	{
		next_line = get_next_line(fd);
		if (next_line == NULL)
			break;
		count++;
		printf("[%d]:%s", count, next_line);
		free (next_line);
		next_line = NULL;
	}
	close(fd);
	return(0);
}
