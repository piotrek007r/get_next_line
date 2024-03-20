
#include "get_next_line.h"

// void ft_putstr(char *str)
//{
//	while (*str)
//	{
//		write(1, str, 1);
//		str++;
//	}
//	write(1, "\n", 1); // need if statement for end of file
// }

char *ft_strdup(const char *str)
{
	char *temp;
	unsigned int counter;

	temp = (char *)malloc(ft_strlen(str) + 1);
	if (!temp)
		return (NULL);
	counter = 0;
	while (str[counter])
	{
		temp[counter] = str[counter];
		counter++;
	}
	temp[counter] = '\0';
	return (temp);
}

char *ft_read(int fd)
{
	int bytes_read;
	char *temp;
	char *buffer;
	char *line;
	buffer = NULL;
	line = NULL;

	while (1)
	{
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		buffer[bytes_read] = '\0';
		if (!line)
			line = ft_strdup(buffer);
		else
		{
			temp = line;
			line = ft_strjoin(temp, buffer);
			//free(temp);
			temp = NULL;
		}
		if (ft_strchr(buffer, '\n') == NULL)
		{
			free(buffer);
			buffer = NULL;
		}
		else
		{
			free(buffer);
			buffer = NULL;
			break;
		}
	}
	return line;
}

char *get_next_line(int fd)
{
	int bytes_read;
	static char *reminder;
	char *line;
	char *linetoprint;

	line = ft_read(fd);

	linetoprint = ft_beforenewline(line);
	printf("Line ready to return: %s\n", linetoprint);
	reminder = ft_afternewline(line);
	printf("Now after has this: %s\n", reminder);

	return (linetoprint);
}

int main()
{
	int fd;
	int counter;

	fd = open("test2.txt", O_RDONLY);
	counter = 0;
	while (counter < 1)
	{
		printf("FINAL OUTPUT %s", get_next_line(fd));
		counter++;
	}
	close(fd);
}

// if (bytes_read == 0)
