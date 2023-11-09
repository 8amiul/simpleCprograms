#include <stdio.h>

#define SIZE 100
#define INITIAL 0

static char line[SIZE];

static int inp(void);
static void recurRev(int i, int c);

int main(void)
{
	recurRev(INITIAL, inp());
	printf("%s\n", line);
}

static int inp(void)
{
	int i = 0;
	char c;

	while ((c = getchar()) != '\n')
		line[i++] = c;
	line[++i] = '\0';

	return --i;
}

static void recurRev(int i, int c)
{
	if (i == c / 2)
		return;

	int j = c - i - 1;

	char temp = line[i];
	line[i] = line[j];
	line[j] = temp;
	recurRev(++i, c);
}
