/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruszkie <pruszkie@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:21:15 by pruszkie          #+#    #+#             */
/*   Updated: 2024/03/22 18:30:30 by pruszkie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char    *ft_read(int fd, char *reminder, char *buffer);
static char    *_set_line(char *line);
static char    *ft_strchr(char *s, int c);

    static char *reminder;
char    *get_next_line(int fd)
{
    char        *line;
    char        *buffer;

    buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0) // <-DELATE THIS
    {
        free(reminder);
        free(buffer);
        reminder = NULL;
        buffer = NULL;
        return (NULL);
    }
    if (!buffer)
        return (NULL);
    line = ft_read(fd, reminder, buffer);
    free(buffer);
    buffer = NULL;
    if (!line)
        return (NULL);
    reminder = _set_line(line);
    return (line);
}

static char *_set_line(char *line_buffer)
{
    char    *reminder;
    ssize_t    i;

    i = 0;

    while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
        i++;

    if (line_buffer[i] == 0 || line_buffer[1] == 0)
        return (NULL);
    reminder = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
    if (*reminder == 0)
    {
        free(reminder);
        reminder = NULL;
    }

    line_buffer[i + 1] = 0;
    return (reminder);
}

static char	*ft_read(int fd, char *reminder, char *buffer)
{
	ssize_t	bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		// where is allocating for buffer
		if (bytes_read == -1)
		{
			free(reminder);
			return (NULL);
		}

		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = 0;

		if (!reminder)
			reminder = ft_strdup("");
		temp = reminder; // why here is no strdup
		reminder = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;

		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (reminder);
}

static char	*ft_strchr(char *s, int c)
{
	unsigned int	i;
	char			cc;

	cc = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char *) &s[i]);
	return (NULL);
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
