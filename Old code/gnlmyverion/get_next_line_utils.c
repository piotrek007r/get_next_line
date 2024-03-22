#include "get_next_line.h"

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
	free((void *)s1);
	//free((void *)s2);
	//printf("string after joining is: %s", str);
	return (str);
}

char *ft_strchr(const char *str, int z)
{
	int i;
	//printf("--looking for a new line---\n");
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
	//free(str);
	before[j] = '\0';
	//printf("line what was before %s\n", before);
	return (before);
}

char *ft_afternewline(char *str)
{
	size_t i;
	size_t j;

	char *after;

	i = 0;
	while (str[i] != '\n')
		i++;

	after = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!after)
		return (NULL);
	j = 0;
	//printf("i is %ld", i);
	//printf("strlen is %ld", ft_strlen(str));

	while (i < ft_strlen(str))
	{
		//printf("str is %c\n", str[j]);
		after[j] = str[i+1];
		j++;
		i++;
	}
	after[j] = '\0';
	//printf("Now after is: %s\n", after);
	return (after);
}


