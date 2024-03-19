#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

//# ifndef BUFFER_SIZE
//#  define BUFFER_SIZE 10000000
//# endif

char *get_next_line(int fd);
void ft_putstr(char *str);
char *ft_afternewline(char *str);
char *ft_beforenewline(char *str);
char *ft_strchr(const char *str, int z);
char *ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);

#endif
