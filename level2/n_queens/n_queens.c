#include <stdlib.h>
#include <unistd.h>

int	n;
int	board[100];

void	ft_putnbr(int num)
{
	char	c;

	if (num >= 10)
		ft_putnbr(num / 10);
	c = (num % 10) + '0';
	write(1, &c, 1);
}

void	print_solution(void)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putnbr(board[i]);
		if (i < n - 1)
			write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}

int	is_safe(int col, int row)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (board[i] == row)
			return (0);
		if (board[i] - i == row - col)
			return (0);
		if (board[i] + i == row + col)
			return (0);
		i++;
	}
	return (1);
}

void	solve(int col)
{
	int	row;

	if (col == n)
	{
		print_solution();
		return ;
	}
	row = 0;
	while (row < n)
	{
		if (is_safe(col, row))
		{
			board[col] = row;
			solve(col + 1);
		}
		row++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	n = atoi(argv[1]);
	if (n <= 0)
		return (1);
	solve(0);
	return (0);
}
