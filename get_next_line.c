#include "get_next_line.h"


char	*get_buffer(int fd, char *line)
{
	char *buff;
	int bytes;

	if(!line)
		line = calloc(1, 1);

	bytes = 1;
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (!ft_strchr(line, '\n') && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
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
	char *str;
	size_t length;

	new = strchr(buff, '\n');

	if (!buff || !new)
		return (NULL);

	length = new - buff + 1;
	str = ft_strndup(buff, length);
	// printf("new : %s \n\n", str);
	return (str);
}
// Move the buffer to the next ocurrency. then return a new buffer.
char	*ft_realloc(char *buff)
{
	char *str;
	size_t length;
	char *result;

	if (!buff)
		return (NULL);

	str = ft_strchr(buff, '\n');
	if (!str)
	{
		free(buff);
		return (NULL);
	}

	length = str - buff;

	result = ft_strndup(buff + length + 1, length);

	free(buff);
	return (result);
}

char	*get_next_line(int fd)
{
	static char *buff;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);

	buff = get_buffer(fd, buff);
	if (!buff)
		return (NULL);
	line = get_next(buff);
	buff = ft_realloc(buff);
	return (line);
}

int	main(void)
{
	int fd = open("test2.txt", O_RDONLY);
	char *line;
	int i = 0;

	if (fd < 0)
	{
		printf("Something went wrong opening test.txt");
		return (1);
	}

	line = get_next_line(fd); // Initialize line before entering the loop

	while (line != NULL)
	{
		printf("line [%02d]: %s\n", i, line);
		free(line);
		i++;
		line = get_next_line(fd); // Get the next line
	}
	close(fd);
	return (0);
}
