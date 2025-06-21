/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: texenber <texenber@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 11:54:49 by texenber          #+#    #+#             */
/*   Updated: 2025/06/21 13:06:54 by texenber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *bigger_buffer)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!ft_strchr(bigger_buffer, '\n')
	str = malloc((ft_strlen(bigger_buffer) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (bigger_buffer[i] != '\0' && bigger_buffer[i] != '\n')
	{
		str[i] = bigger_buffer[i];
		i++;
	}
	str[i] = '\0';	
	return (str);
}
