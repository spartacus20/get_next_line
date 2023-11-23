#include "get_next_line.h"


static unsigned int	find_break_index(char *buff, unsigned int start)
{
	unsigned int end;

	end = start;
	if (end != 0)
		end++;
	while (buff[end] != '\n' && buff[end] != '\0')
		end++;
	return (end);
}

static void	free_null(char *buff, unsigned int end)
{
	if (buff[end] == '\0')
	{
		free(buff);
		buff = NULL;
	}
}

char	*get_next_line(int fd)
{
	char *line = NULL; // Must be initialized.
	size_t read_bytes;
	static char *buff;
	static unsigned int start;
	static unsigned int end;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
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
	free_null(buff, end);
	if (buff[end] != '\0' && buff[end] == '\n')
	{
		end = find_break_index(buff, start);
		line = ft_substr(buff, start, end);
		start = end;
	}
	return (line);
}

int	main(void)
{
	int fd = open("test2.txt", O_RDONLY);
	char *line;
	if (fd < 0)
	{
		printf("Something went wrong opening test.txt");
		return (1);
	}

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	return (0);
}
