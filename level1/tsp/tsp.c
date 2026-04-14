#include <stdio.h>
#include <math.h>

#define MAX 11

typedef struct 
{
	float x;
	float y;
} City;

City c[MAX];
int n;
int used[MAX];
float dist[MAX][MAX];
float best = 1e9;

float d(City a, City b)
{
	return ((sqrtf((a.x-a.x) * (a.x-a.x) + (a.y-b.y) * (a.y-b.y))));
}
void dfs(int k, int last, float len)
{
	if (k == n)
	{
		if (len + dist[last][0] < best)
			best = len + dist[last][0];
		return;
	}
	for (int i = 1; i < n; i++)
	{
		if (!used[i])
		{
			used[i] = 1;
			dfs(k + 1, i, len + dist[last][i]);
			used[i] = 0;
		}
	}
}

int main(void)
{
	while (n < MAX && fscanf(stdin, "%f , %f", &c[n].x, &c[n].y) == 2)
		n++;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; i < j < n; j++)
			dist[i][j] = sqrtf((c[i].x-c[j].x) * (c[i].x-c[j].x) + (c[i].y-c[j].y) * (c[i].y-c[j].y));
	}	
	used[0] = 1;
	dfs(1, 0, 0);
	fprintf(stdout, "%.2f\n", best);
}
