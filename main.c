#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	int fd;
	char *line;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Dosya açılamadı");
		return (1);
	}
	//perror("dosyaacıldi");
	while ((line = get_next_line(fd)) != NULL)
	{
		//perror("line");
		printf("satır: %s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}
