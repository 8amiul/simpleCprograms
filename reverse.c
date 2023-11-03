#include <stdio.h>
#define SIZE 1000
/* Prints the inputed string in reverse order. */

int input();
void print(char [], int);
char string[SIZE];


int main()
{
	extern char string[SIZE];
	int c = input();
	print(string, --c);
	return 0;
}


int input()
{
	extern char string[SIZE];
	char c;
	int pos = 0;

	while ((c = getchar()) != '\n')
	{
		string[pos] = c;
		++pos;
	}
	++pos;
	string[pos] = '\0';
	return pos;
}

void print(char a[], int c)
{
	for (int i = c-1; i >= 0; --i)
	{
		printf("%c", a[i]);
	}
	printf("\n");
}
