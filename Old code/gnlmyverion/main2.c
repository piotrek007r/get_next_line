
//#include "get_next_line.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>


//#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	counter;

	if (!str)
		return (0);
	counter = 0;
	while (str[counter] != '\0')
		counter++;
	return (counter);
}

char *ft_strjoin(char const *s1, char const *s2)
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
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i++] = s2[j++];
	}
	str[i] = '\0';
	return (str);
}

char *ft_strchr(const char *str, int z)
{
	int i;

	i = 0;
	if	(!str)
		return (NULL);
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

char *ft_beforenewline(char *str)
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
	before[j] = '\0';
	return (before);
}

char *ft_afternewline(char *str)
{
	while (*str)
	{
		if(*str == '\n')
		{
			return str+1;
		}
		str++;
	}
	return str;
}





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
	while(counter < 3)
	{
		printf("%s\n",get_next_line(fd));
		counter++;
	}
}
