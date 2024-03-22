
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
	//free((char *)str);
	temp[counter] = '\0';
	return (temp);
}

char *ft_read(int fd, char *reminder)
{
	int bytes_read;
	char *temp;    // temp string to transfer data between buffer abd line
	char *buffer;  // string after read
	char *line;	   // line constructed from joined buffers contained new line
	buffer = NULL;
	line = NULL;

		if (reminder)
		{
			line = ft_strdup(reminder);
			free(reminder);
		}
	while (1)
	{
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1 || bytes_read == 0)
			{
			free(buffer);
			free(reminder);
			return (NULL);
			}
		buffer[bytes_read] = '\0';
		if (!line)
			line = ft_strdup(buffer);
		else
		{
			temp = line; // check if this doesnt require strdup
			line = ft_strjoin(temp, buffer);
			//free(temp);
			temp = NULL;
		}
		if (ft_strchr(buffer, '\n') == NULL || ft_strchr(buffer, '\0') == NULL)
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
	static char *reminder;

char *get_next_line(int fd)
{
	char *line;
	char *linetoprint;
	line = NULL;

	//if (!reminder)

	if (ft_strchr(reminder, '\n') != NULL)
	{
		//printf("Reminder from previous call was: %s\n", reminder);
		line = ft_strdup(reminder);
		free(reminder);

	}
	else
		line = ft_read(fd, reminder);

	if (!line)
		return (NULL);
	linetoprint = ft_beforenewline(line);
	//printf("Line ready to return: %s\n", linetoprint);
	reminder = ft_afternewline(line);
	//printf("Now reminder has this: %s\n\n", reminder);
	free(line);
	return (linetoprint);
}

//int main()
//{
//	int fd;
//	int counter;

//	fd = open("test2.txt", O_RDONLY);
//	counter = 0;
//	while (counter < 4)
//	{
//		//printf("%i-", counter+1);
//		printf("%i-FINAL OUTPUT %s\n\n",counter+1, get_next_line(fd));
//		counter++;
//	}
//	free(reminder);
//	close(fd);
//}

// if (bytes_read == 0)
