#include "get_next_line.h"

char *get_next_line(int fd)
{
	static char buf[1000];
	static int read_b = 0;
	static int pos = 0;

	char *line;
	int i = 0;
	
	line = malloc(100000);

	if(fd<0 || BUFFER_SIZE <= 0 || line == NULL)
	{
		if(line != NULL)
		{
			free(line);
		}
		return NULL;
	}
	while(1)
	{
		if(pos >= read_b)
		{
			pos = 0;
			read_b = read(fd,buf,BUFFER_SIZE);
			if(read_b <= 0)
				break;
		}
		line[i++] = buf[pos++];
		if(line[i-1] == '\n')
			break;
	}
	if(i == 0)
	{
		free(line);
		return NULL;
	}
	line[i] = '\0';
	return line;
}