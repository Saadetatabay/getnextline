/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satabay <satabay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 11:38:40 by satabay           #+#    #+#             */
/*   Updated: 2025/07/16 11:38:41 by satabay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static char	*read_until_new_line(int fd, char *left)
{
	int		byte_red;
	char	*buf;
	char	*temp;

	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	//if (!buf)
	//	return (NULL);
	while (!check_newline(left))
	{
		byte_red = read(fd, buf, BUFFER_SIZE);
		if (byte_red <= 0)
			break ;
		buf[byte_red] = '\0';
		temp = ft_strjoin(left, buf);
		free(left);
		left = temp;
	}
	free(buf);
	return (left);
}

char	*divide_left(char **leftp)
{
	char	*old_left;
	char	*ret;
	char	*newlinepos;
	int		indis;

	if (!leftp || !*leftp)
		return (NULL);
	newlinepos = ft_strchr(*leftp, '\n');
	if (!newlinepos)
		return (NULL);
	indis = newlinepos - *leftp;
	ret = ft_substr(*leftp, 0, indis + 1);
	if (!ret)
		return (NULL);
	old_left = ft_strdup(*leftp + indis + 1);
	if (!old_left)
	{
		free(ret);
		return (NULL);
	}
	free(*leftp);
	*leftp = old_left;
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*left;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!left)
		left = ft_strdup("");
	left = read_until_new_line(fd, left);
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
