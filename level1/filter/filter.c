#define _GNU_SOURCE
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

int	main(int argc, char **argv)
{
	char	str[50000];
	int		total = 0;
	int		bytes_read = 0;
	size_t	i;
	char	*pattern;

	if ((argc != 2) || !argv[1] || (argv[1][0] == '\0'))
		return (1);
	while (1)
	{
		bytes_read = read(0, str + total, 50000 - total); 
		if (bytes_read < 0)
		{
			perror("read");
			return (1);
		}
		if (bytes_read == 0)
			break ;
		total += bytes_read;
	}
	str[total] = '\0';
	pattern = str;
	while (1)
	{
		pattern = memmem(pattern, total - (pattern - str), argv[1], strlen(argv[1]));
		if (pattern == NULL)
			break ;
		i = 0;
		while (i < strlen(argv[1]))
			pattern[i++] = '*';
	}
	printf("%s", str);
	return (0);	
}