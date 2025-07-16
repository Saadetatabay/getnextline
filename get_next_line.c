#include "get_next_line.h"

int	check_newline(char *buf)
{
	if (!buf || !*buf)
		return (0);
	while (*buf)
	{
		if (*buf == '\n')
			return (1);
		buf++;
	}
	return (0);
}

char	*divide_left(char **leftp)
{
	char	*old_left;
	char	*ret;
	int		indis;
	char	*new_pos;

	new_pos = ft_strchr(*leftp, '\n');
	indis = new_pos - *leftp;
	ret = ft_substr(*leftp, 0, indis + 1);
	old_left = ft_strdup(*leftp + indis + 1);
	free(*leftp);
	*leftp = old_left;
	return (ret);
}

char	*get_next_line(int fd)
{
	int			byte_red;
	static char	*left;
	char		*buf;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return NULL;
	if (!left)
		left = ft_strdup("");
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buf)
		return NULL;	
	while (!check_newline(buf))
	{
		byte_red = read(fd, buf, BUFFER_SIZE);
		if (byte_red <= 0)
			break;
		buf[byte_red] = '\0';
		temp = ft_strjoin(left, buf);
		free(left);
		left = temp;
	}
	if (!*left)
	{
		free(left);
		left = NULL;
		return (NULL);
	}
	if (!check_newline(left))
	{
		temp = ft_strdup(left);
		free(left);
		left = ft_strdup("");
		return (temp);
	}
	temp = divide_left(&left);
	return (temp);
}
