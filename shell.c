#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int  main ()
{
	char *buffer, *token;
	size_t bufsize = 32;
	size_t characters;

	buffer = malloc(bufsize * sizeof(char));
	if (buffer == NULL)
		return (0);
	write(1, "$ ", 2);
	characters = getline(&buffer,&bufsize,stdin);
	token = strtok(buffer, " ");
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}
	return (0);
}
