#include "monty.h"
/**
 * check_dig - check is string is only digit
 * @s: string to be searched
 * Return: 1 if only digit -1 if not
**/
int check_dig(char *s)
{
	int i;

	if (s[0] == '-')
		i = 1;

	for ( ; s[i] != '\0'; i++)
	{
		if (s[i] < 48 || s[i] > 57)
			return (-1);
	}
	return (0);
}
