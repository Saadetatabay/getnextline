/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satabay <satabay@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 15:27:04 by satabay           #+#    #+#             */
/*   Updated: 2025/07/11 11:13:19 by satabay          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i) != '\0')
		i++;
	return (i);
}

static void	concatenate(char *cat, const char *s, int *j)
{
	int	i;

	i = 0;
	while (*(s + i))
	{
		*(cat + *j) = *(s + i);
		i++;
		(*j)++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cat;
	int		len;
	int		j;

	if (s1 == NULL)
		return (ft_strdup(s2));
	j = 0;
	len = 0;
	len = ft_strlen(s1);
	len += ft_strlen(s2);
	cat = (char *)malloc(sizeof(char) * (len + 1));
	if (!cat)
		return (0);
	concatenate(cat, s1, &j);
	concatenate(cat, s2, &j);
	*(cat + j) = '\0';
	return (cat);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((char)c == *s)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*a;
	size_t	i;
	size_t	len_s;

	i = 0;
	len_s = ft_strlen(s);
	if (!s || start >= len_s || len == 0)
		return (ft_strdup(""));
	if (len > len_s - start)
		len = len_s - start;
	a = (char *)malloc(sizeof(char) * (len + 1));
	if (!a)
		return (0);
	while (s[start + i] && i < len)
	{
		a[i] = s[start + i];
		i++;
	}
	a[i] = '\0';
	return (a);
}
char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	len;
	char	*copy;

	len = ft_strlen(s);
	copy = malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (0);
	i = 0;
	while (i < len)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n--)
	{
		*p = 0;
		p++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*c;

	c = malloc(size * nmemb);
	if (!c)
		return (NULL);
	ft_bzero(c, nmemb * size);
	return (c);
}
