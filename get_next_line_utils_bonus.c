#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

bool	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (true);
		i++;
	}
	return (false);
}

char	*ft_strdup(char *str)
{
	char	*newstr;
	int		i;

	newstr = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	i = 0;
	while (str[i])
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*jstr;
	int		i;
	int		j;

	jstr = (char *)malloc((ft_strlen(s1) + 1) + (ft_strlen(s2) + 1));
	i = 0;
	while (s1[i])
	{
		jstr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		jstr[i] = s2[j];
		j++;
		i++;
	}
	jstr[i] = '\0';
	free(s1);
	return (jstr);
}

char	*ft_substr(char *line, int pos, int len)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		str[i] = line[pos];
		i++;
		pos++;
	}
	str[i] = '\0';
	return (str);
}