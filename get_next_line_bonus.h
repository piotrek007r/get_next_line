#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# ifndef FDS
#  define FDS 1000
# endif
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdbool.h>

// main

char	*get_next_line(int fd);
char	*ft_join_buffer(char *buffer, char *leftoov, int fd);
char	*ft_split_line(char *line);

// utils

int	ft_strlen(char *str);
bool	ft_strchr(char *str, char c);
char	*ft_strdup(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *line, int pos, int len);

#endif