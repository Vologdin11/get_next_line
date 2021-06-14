#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*strRes;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	strRes = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!strRes)
		return (0);
	while (s1[j])
	{
		strRes[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j])
		strRes[i++] = s2[j++];
	strRes[i] = '\0';
	return (strRes);
}

char	*ft_strdup(const char *str)
{
	int		size;
	int		i;
	char	*copy;

	i = 0;
	size = ft_strlen(str) + 1;
	copy = (char *)malloc(size);
	if (copy == NULL)
		return (NULL);
	while (i < size)
	{
		copy[i] = str[i];
		i++;
	}
	return (copy);
}

char	*ft_strchr(const char *str, int ch)
{
	char	*res;

	res = (char *)str;
	if (ch == 0)
	{
		return (res + ft_strlen(str));
	}
	while (*res != 0)
	{
		if (*res == (unsigned char)ch)
		{
			return (res);
		}
		res++;
	}
	return (NULL);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*subS;

	i = 0;
	if (!s)
		return (0);
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	subS = (char *)malloc(len + 1);
	if (subS == 0)
		return (0);
	while (s[start] && i < len)
	{
		if (start > ft_strlen(s))
			break ;
		subS[i] = s[start];
		i++;
		start++;
	}
	subS[i] = 0;
	return (subS);
}
