#include <stdlib.h>
#include <stdio.h>

int	*g_set;
int	g_len;
int	g_target;

void solve(int idx, int sum, int *subset, int sublen)
{
	if (sum == g_target)
	{
		for (int i = 0; i < sublen; i++)
			printf("%d%c", subset[i], i < sublen - 1 ? ' ' : '\n');
		if (sublen == 0)
			printf("\n");
	}
	if (idx >= g_len)
		return;
	for (int i = idx; i < g_len; i++)
	{
		subset[sublen] = g_set[i];
		solve(i + 1, sum + g_set[i], subset, sublen + 1);
	}
}

int main(int ac, char **av)
{
	if (ac < 2)
		return 1;
	g_target = atoi(av[1]);
	g_len = ac - 2;
	g_set = malloc(sizeof(int) * g_len);
	int *subset = malloc(sizeof(int) * g_len);
	if (!g_set || !subset)
		return free(g_set), free(subset), 1;
	for (int i = 0; i < g_len; i++)
		g_set[i] = atoi(av[i + 2]);
	solve(0, 0, subset, 0);
	free(g_set);
	free(subset);
	return 0;
}
