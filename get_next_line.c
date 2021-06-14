#include "get_next_line.h"

static int	ft_writeLine(char **dest, char **src)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while ((*src)[i] != '\n' && (*src)[i] != '\0')
		i++;
	if ((*src)[i] == '\n')
	{
		*dest = ft_substr(*src, 0, i);
		tmp = ft_strdup(*src + (i + 1));
		free(*src);
		*src = tmp;
	}
	else
	{
		*dest = ft_strdup(*src);
		free(*src);
		*src = NULL;
	}
	if (*src != '\0')
		return (1);
	return (0);
}

static int	ft_result(long readByte, char **save, char **line)
{
	if (readByte < 0)
		return (-1);
	else if (readByte == 0 && save == NULL)
		return (0);
	return (ft_writeLine(line, save));
}

int	get_next_line(int fd, char **line)
{
	long		readByte;
	char		*tmp;
	char		buf[BUFFER_SIZE + 1];
	static char	*save;

	readByte = 1;
	while (readByte > 0)
	{
		readByte = read(fd, &buf, BUFFER_SIZE);
		if (readByte < 0 || line == NULL)
			return (-1);
		buf[readByte] = '\0';
		if (save != NULL)
		{
			tmp = ft_strjoin(save, buf);
			free(save);
			save = tmp;
		}
		else
			save = ft_strdup(buf);
		if (ft_strchr(save, '\n'))
			break ;
	}
	return (ft_result(readByte, &save, line));
}
