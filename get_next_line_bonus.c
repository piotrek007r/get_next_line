#include "get_next_line_bonus.h"

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
	static char	*leftoov[FDS];
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
	line = ft_join_buffer(buffer, leftoov[fd], fd);
	free(buffer);
	if (!line)
		return (NULL);
	leftoov[fd] = ft_split_line(line);
	return (line);
}

// int	main(void)
// {
// 	int	arr[3];
// 	int i;
// 	char *line;

// 	arr[0] = open("file1.txt", O_RDONLY);
// 	arr[1] = open("file2.txt", O_RDONLY);
// 	arr[2] = open("file3.txt", O_RDONLY);

// 	i = 0;
// 	while (i < 5)
// 	{

// 		printf("call num: %d\n", i);
// 		line = get_next_line(arr[0]);
// 		printf("line: %s\n", line);
// 		line = get_next_line(arr[1]);
// 		// printf("line: %s\n", line);
// 		line = get_next_line(arr[2]);
// 		// printf("line: %s\n", line);
// 		// printf("----------------------------");
// 		i++;
// 	}
// 	close(arr[0]);
// }