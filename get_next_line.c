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
	char *buff;
	int bytes;

	if (!line)
		line = calloc(1, 1);
	bytes = 1;
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	// Grow the buffer with join for each call.
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
	char *new;
	int i;

	i = 0;
 	if(!buff[i])
		return NULL;
	while(buff[i] && buff[i] != '\n')
		i++;
	new = ft_strndup(buff, i + 1);
	return new;
}

// Move the buffer to the next ocurrency. The delete the previous buffer and return a new one.
char	*ft_realloc(char *buff)
{
	char *str;
	char *result;

	if (!buff)
		return (NULL);
	str = ft_strchr(buff, '\n');
	if (!str)
	{
		free(buff);
		return (NULL);
	}
	result = ft_strndup(str + 1 , strlen(str + 1)); //Changed the way how to count the  lenght.
	free(buff);
	return (result);
}

char	*get_next_line(int fd)
{
	static char *buff;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = get_buffer(fd, buff);
	if (!buff)
		return (NULL);
	line = get_next(buff);
	buff = ft_realloc(buff);
	return (line);
}

// int	main(void)
// {
// 	int fd = open("test3.txt", O_RDONLY);
// 	char *line;
// 	int i = 0;

// 	if (fd < 0)
// 	{
// 		printf("Something went wrong opening test.txt");
// 		return (1);
// 	}

// 	line = get_next_line(fd); // Initialize line before entering the loop
// 	// printf("line [%02d]: %s\n", i, line);
// 	// free(line);
// 	while (line != NULL)
// 	{
// 		printf("line [%02d]: %s\n", i, line);
// 		free(line);
// 		i++;
// 		line = get_next_line(fd); // Get the next line
// 	}
// 	close(fd);
// 	return (0);
// }
