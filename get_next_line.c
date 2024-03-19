
#include "get_next_line.h"



void ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1); // need if statement for end of file
}

char *get_next_line(int fd)
{
	int bytes_read;
	char *buffer;
	static	char *concatedstr;
	char *str;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read == 0)
	{
		if (ft_strlen(concatedstr) == 0)
		{
			free(concatedstr);
			return NULL; // mayby add free concatedstr
		}
		str = ft_beforenewline(concatedstr);
		concatedstr = ft_afternewline(concatedstr);
	}
	if (ft_strchr(buffer, '\n') == NULL)
		concatedstr = ft_strjoin(concatedstr, buffer);
	else
	{
		str = ft_strjoin(concatedstr, ft_beforenewline(buffer));
		free(concatedstr);
		concatedstr = ft_afternewline(buffer);
	}
	//free(buffer);
	return str;
}



int main()
{
	int fd;
	int counter;

	fd = open("test.txt", O_RDONLY);
	counter = 0;
	while(counter < 1)
	{
		printf("%s",get_next_line(fd));
		counter++;
	}
	close(fd);
}
