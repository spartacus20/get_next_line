#include "get_next_line.h"

char	*get_buffer(int fd, char *line)
{
	char *buff;
	int bytes;

	if (!line)
		line = ft_calloc(1, 1);
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
	return (str);
}
// Move the buffer to the next ocurrency. then return a new buffer.
char	*ft_realloc(char *buff)
{
	char *str;
	if (!buff)
		return (NULL);

	str = ft_strchr(buff, '\n');
	free(buff);
	if (!str)
		return (NULL);
	return (ft_strndup(str, ft_strlen(str) + 1));
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


int main(void)
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

    while (line)
    {
        printf("line [%02d]: %s", i, line);
        free(line);
        i++;

        line = get_next_line(fd); // Get the next line
    }

    return (0);
}
