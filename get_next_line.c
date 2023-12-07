/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: jotomas- <jotomas-@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2023/11/29 16:19:28 by jotomas-          #+#    #+#             */
/*   Updated: 2023/11/29 16:19:28 by jotomas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_buffer(int fd, char *line)
{
	char	*buff;
	int		bytes;

	if (!line)
		line = 	ft_calloc(1, 1);
	bytes = 1;
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (!ft_strchr(line, '\n') && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(line);
			free(buff);
			return (NULL);
		}
		buff[bytes] = '\0';
		line = ft_strjoin(line, buff);
	}
	free(buff);
	return (line);
}

// Move to the next line.
char	*get_next(char *buff)
{
	char	*new;
	int		i;

	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	new = ft_strndup(buff, i + 1);
	return (new);
}

/*  Move the buffer to the next ocurrency.
The delete the previous buffer and return a new one.
*/
char	*ft_realloc(char *buff)
{
	char	*str;
	char	*result;

	if (!buff)
		return (NULL);
	str = ft_strchr(buff, '\n');
	if (!str)
	{
		free(buff);
		return (NULL);
	}
	result = ft_strndup(str + 1, ft_strlen(str + 1));
	free(buff);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = get_buffer(fd, buff);
	if (!buff)
		return (NULL);
	line = get_next(buff);
	buff = ft_realloc(buff);
	return (line);
}
