#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int  main ()
{
	char *buffer, *token;
	size_t bufsize = 32;
	size_t characters;
	char *argv[] = {"", NULL};
	int i;

	i = 0;
	buffer = malloc(bufsize * sizeof(char));
	if (buffer == NULL)
		return (0);
	write(1, "$ ", 2);
	characters = getline(&buffer,&bufsize,stdin);
	argv[0] = strtok(buffer, "\n");
	execve(argv[0], argv, NULL);
	while(argv[i] != NULL)
	{
		printf("text: %s\n", argv[i]);
		i++;
	}
	/* while (token != NULL) */
	/* { */
	/* 	printf("%s", token); */
	/* 	token = strtok(NULL, " "); */
	/* } */
	return (0);
}
