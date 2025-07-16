/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satabay <satabay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:03:27 by satabay           #+#    #+#             */
/*   Updated: 2025/07/07 18:27:33 by satabay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	new_line_check(char *string)
{
	if (!string)
		return (0);
	while (*string)
	{
		if (*string == '\n')
			return (1);
		string++;
	}
	return (0);
}

static char	*divide_line(char **rem)
{
	int		i;
	char	*line;
	char	*new_rem;

	i = 0;
	while (*((*rem) + i) != '\n')
		i++;
	if ((*(*rem) + i) == '\n')
		i++;
	line = ft_substr(*rem, 0, i);
	new_rem = ft_strdup(*rem + i);
	free(*rem);
	*rem = new_rem;
	return (line);
}

char	*get_next_line(int fd)
{
	int				byte_red;
	char			buffer[BUFFER_SIZE + 1];
	static char		*remainder;
	char			*ret;
	char			*line;
	char			*temp;

	byte_red = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!remainder)
		remainder = ft_strdup("");
	while (!new_line_check(remainder))
	{
		byte_red = read(fd, buffer, BUFFER_SIZE);
		if (byte_red <= 0)
			break;
		buffer[byte_red] = '\0';
		temp = ft_strjoin(remainder, buffer);
		free(remainder);
		remainder = temp;
	}
	if (!remainder || *remainder == '\0')
	{
		free (remainder);
		remainder = NULL;
		return (NULL);
	}
	ret = ft_strchr(remainder, '\n');
	if (!ret)
	{
		line = ft_strdup(remainder);
		free(remainder);
		remainder = NULL;
		return (line);
	}
	line = divide_line(&remainder);	
	return (line);
}
