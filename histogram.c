/*
	type something hit enter then ctrl-d and something will be printed. That's it.
*/

#include <stdio.h>

#define N 10

int main(void)
{
	int c;
	int a[N];
	int b[N][N];
	int count, step;
	count = step = 0;

	for (int i = 0; i < N; i++) a[i] = 0;

	while ((c = getchar()) != EOF)
	{
		if (c == ' ' | c == '\n' | c == '\t')
		{
			a[step] = count;
			step++;
			count = 0;
		}
		else
			count++;	
		putchar(c);
	}
	
	for (int i = N; i > 0; i--)
	{
		for (int j = 0; j < N; j++)
		{
			if ((a[j] / i) == 0)
				b[N-i][j] = 0;
			else
				b[N-i][j] = 1;
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (b[i][j])
				printf("|");
			else
				printf(" ");
		}
		printf("\n");
	}

	return 0;
}
