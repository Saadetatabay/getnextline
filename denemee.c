#include<stdio.h>
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
int main()
{
    char buffer[BUFFER_SIZE];
    printf("%d",check_newline(buffer));
}