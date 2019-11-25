#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>


/**
 *_atoi - convert a string to an integer.
 *@s: string given by user
 *
 *Return: int with the number of the string
 */
int _atoi(char *s)
{
	unsigned int dig_n;
	int sign, var_dig, var_salida;
	char cara;

	dig_n = 0;
	sign = 1;
	var_dig = 0;
	var_salida = 0;
	while (*s != '\0')
	{
		cara = *s;
		if (cara == '-')
			sign = sign * -1;
		if ((cara >= '0') && (cara <= '9'))
		{
			dig_n = dig_n * 10 + cara - '0';
			var_dig = 1;
			var_salida = 1;
		}
		else
			var_salida = 0;
		if (var_dig == 1 && var_salida == 0)
			break;
		s++;
	}
	return (dig_n * sign);
}

/**
 *_strlen_recursion - calculate the lenght of a recursion
 *@s: string given by user
 *
 *Return: lenght of recursion
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);
	else
		return (1 + _strlen_recursion(s + 1));

}


#endif /* HEADER_H */
