#include <stdlib.h>
#include <unistd.h>

void putstr(char *s)
{
    int i = 0;
    while (s[i])
    {
    	write(1, &s[i], 1);
		i++;
	}
    write(1, "\n", 1);
}

void swap(char *s, int i, int j)              
{
    char t = s[i];
    s[i] = s[j];
    s[j] = t;
}


int next_perm(char *s, int n)
{
	int i = n-2;
	while(i >= 0 && s[i] >= s[i + 1])
		i--;
	if (i < 0)
		return 0;
	int j = n -1;
	while (s[i] >= s[j])
		j--;
	swap(s, i, j);
	for (int a = i + 1, b = n - 1; a < b; a++, b--)
		swap(s, a, b);
	return 1;	
}

void sort(char *s, int n)
{
	for (int i = 0; i < n - 1 ; i++)
	{
		for (int j = i + 1; j < n; j++)
			if (s[i] > s[j])
                swap(s, i, j);
	}
	
}

int main(int ac, char **av)
{
	if (ac != 2)
		return 1;
	int n = 0;
	while (av[1][n])
		n++;
	char *s = malloc(n + 1);
	for (int i = 0; i <= n; i++)
		s[i] = av[1][i];
	sort(s, n);
	do {
		putstr(s);
	} while (next_perm(s, n));
	free(s);
}