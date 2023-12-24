// Still in development

#include <stdio.h>
#include <stdlib.h>

struct morseCode
{
	char a;
	char *b;
} keys[] = {
	{'a', ".-"},
	{'b', "-..."},
	{'c', "-.-."},
	{'d', "-.."},
	{'e', "."},
	{'f', "..-."},
	{'g', "--."},
	{'h', "...."},
	{'i', ".."},
	{'j', ".---"},
	{'k', "-.-"},
	{'l', ".-.."},
	{'m', "--"},
	{'n', "-."},
	{'o', "---"},
	{'p', ".--."},
	{'q', "--.-"},
	{'r', ".-."},
	{'s', "..."},
	{'t', "-"},
	{'u', "..-"},
	{'v', "...-"},
	{'w', ".--"},
	{'x', "-..-"},
	{'y', "-.--"},
	{'z', "--.."},
	{'1', ".----"},
	{'2', "..---"},
	{'3', "...--"},
	{'4', "....-"},
	{'5', "....."},
	{'6', "-...."},
	{'7', "--..."},
	{'8', "---.."},
	{'9', "----."},
	{'0', "-----"}
};

char *returnMorse(char x);

int main()
{
	char *BUFFER = (char *) malloc(1000 * sizeof(char));
	printf("\t\tMorseCode Translator\t\t\n");
	printf("-> ");
	fgets(BUFFER, 1000, stdin);

	while (*BUFFER != '\0')
	{
		int i = 0;
		printf("%s", returnMorse(BUFFER[i]));
		printf(" ");
		BUFFER++;
		i++;
	}

	//printf("%s", returnMorse(BUFFER[0]));
}

char *returnMorse(char x)
{
	struct morseCode *ptr = keys;
	if (x >= 65 && x <= 90) x += (26 + 6);
	while (1)
	{
		if (ptr->a == x) return ptr->b;
		ptr++;
	}
}
