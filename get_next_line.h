#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

char *get_next_line(int fd);
void ft_putstr(char *str);
char *ft_afternewline(char *str);
char *ft_beforenewline(char *str);
char *ft_strchr(const char *str, int z);
char *ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);

#endif

//char *ft_read(int fd)
//{
//	int bytes_read;
//	char *buffer;
//	char *temp;
//	char *line;
//	buffer = NULL;
//	line = NULL;

//	while (1)
//	{
//		printf("---initialization loop check\n");
//		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
//		if (!buffer)
//			return (NULL);
//		bytes_read = read(fd, buffer, BUFFER_SIZE);
//		buffer[bytes_read] = '\0';
//		if(!line)
//		{
//			line = ft_strdup(buffer);
//		}
//		else
//		{
//			temp = line;
//			line = ft_strjoin(temp, buffer);
//			free(temp);
//			temp = NULL;
//		}
//		printf("Now temp has this: %s\n", temp);

//		if (ft_strchr(buffer, '\n') == NULL)
//		{
//			free(buffer);
//			buffer = NULL;
//			printf("Buffer has this: %s\n", buffer);
//		}
//		else
//		{
//			free(buffer);
//			buffer = NULL;
//			break;
//		}
//	}
//	return (line);
//}
