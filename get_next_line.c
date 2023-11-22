/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: jotomas- <jotomas-@student.42london.com    +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2023/11/22 12:39:34 by jotomas-          #+#    #+#             */
/*   Updated: 2023/11/22 12:39:34 by jotomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

unsigned int	find_break_index(char *buff, unsigned int start)
{
	unsigned int	end;

	end = start;
	if (end != 0)
		end++;
	while (buff[end] != '\n' && buff[end] != '\0')
		end++;
	return (end);
}

char	*get_next_line(int fd)
{
	char	*line;
	size_t	read_bytes;
	static char	*buff;
	static unsigned int	start;
	static unsigned int	end;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!buff)
	{
		buff = calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buff)
			return (NULL);
		read_bytes = read(fd, buff, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_bytes] = '\0';
	}
	end = find_break_index(buff, start);
	line = ft_substr(buff, start, end);
	start = end;
	return (line);
}
