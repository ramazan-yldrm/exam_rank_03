#include <unistd.h>

int main(int ac, char **av)
{
	if (ac != 2) return 1;
	char *s = av[1];
	int n = 0, i, j;
	while (s[n]) n++;
	if (!n) return 0;

	
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			if (s[i] > s[j]) { char t = s[i]; s[i] = s[j]; s[j] = t; }

	
	while (1)
	{
		write(1, s, n);
		write(1, "\n", 1);
		i = n - 2;
		while (i >= 0 && s[i] >= s[i + 1]) i--;
		if (i < 0) break;
		j = n - 1;
		while (s[j] <= s[i]) j--;
		char t = s[i]; s[i] = s[j]; s[j] = t;
		for (int l = i + 1, r = n - 1; l < r; l++, r--)
			{ t = s[l]; s[l] = s[r]; s[r] = t; }
	}
	return 0;
}
