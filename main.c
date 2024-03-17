#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 25
#endif

static	char *newline;

static size_t	ft_strlen(const char *str)
{
	size_t	counter;

	counter = 0;
	while (str[counter] != '\0')
		counter++;
	return (counter);
}

static char *ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (s1 == NULL)
		s1 = ""; // might by problematic with alloc
	str = (char *)malloc(ft_strlen(s1)+ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i++] = s1[i];
	}
	j = 0;
	while (s2[j])
	{
		str[i++] = s2[j++];
	}
	str[i] = '\0';
	return (str);
}

static char *ft_strchr(const char *str, int z)
{
	int i;

	i = 0;
	while (str[i] && str[i] != (char)z)
	{
		i++;
	}
	if (str[i] == (char)z)
	{
		return ((char *)&str[i]);
	}
	return (NULL);
}

static char *ft_beforenewline(char *str)
{
	size_t i;
	size_t j;

	char *before;

	i = 0;
	while (str[i] != '\n')
		i++;

	before = (char *)malloc(sizeof(char) * i + 1);
	if (!before)
		return (NULL);
	j = 0;
	while (j < i)
	{
		before[j] = str[j];
		j++;
	}
	//printf("\nUWAGA!!!  :%s\n", before);
	return (before);
}


char *get_next_line(int fd)
{
	int bytes_read;
	char *buffer;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);

		//printf("Here: %s\n", ft_beforenewline(buffer));
	if (ft_strchr(buffer, '\n') == NULL)
	newline = ft_strjoin(newline, buffer);
	else
	{
		newline = ft_strjoin(newline, ft_beforenewline(buffer));
		//buffer = ft_afternewline(buffer);
	}
	return newline;
}



int main()
{
	int fd;
	fd = open("test.txt", O_RDONLY);
	//get_next_line(fd);
	printf("%s\n", get_next_line(fd));
	//printf("%s\n", get_next_line(fd));
}
