#include "get_next_line.h"

char	*ft_join_buffer(char *buffer, char *leftoov, int fd)
{
	int	bytes_read;

	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if ((bytes_read <= 0) || (buffer == NULL))
			return (leftoov);
		buffer[bytes_read] = '\0';
		if (!leftoov)
			leftoov = ft_strdup("");
		leftoov = ft_strjoin(leftoov, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (leftoov);
}

char	*ft_split_line(char *line)
{
	int		i;
	char	*leftoov;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == 0 || line[1] == 0)
		return (NULL);
	leftoov = ft_substr(line, i + 1, (ft_strlen(line) - i));
	if (*leftoov == 0)
	{
		free(leftoov);
		leftoov = NULL;
	}
	line[i + 1] = '\0';
	return (leftoov);
}

char	*get_next_line(int fd)
{
	static char	*leftoov;
	char		*line;
	char		*buffer;

	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer);
		return (NULL);
	}
	line = ft_join_buffer(buffer, leftoov, fd);
	free(buffer);
	if (!line)
		return (NULL);
	leftoov = ft_split_line(line);
	return (line);
}

// int main()
// {
// 	int fd;
// 	int counter;

// 	fd = open("file1.txt", O_RDONLY);
// 	counter = 0;
// 	while (counter < 3)
// 	{
// 		// printf("%i-", counter+1);
// 		printf("%i-FINAL OUTPUT %s\n\n", counter + 1, get_next_line(fd));
// 		counter++;
// 	}
// 	// free(reminder);
// 	close(fd);
// }