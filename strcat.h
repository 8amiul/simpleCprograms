char *strcat_(char *x, char *y)
{
	if (x < y) return NULL;
	char *kx = x;
	for (; *x != '\0'; x++);
	for (; *y != '\0'; (*x++ = *y++));
	return kx;
}
