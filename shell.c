#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int _strcmp(char *s1, char *s2)
{
       int compare, i;
       for (i = 0; s2[i] != '\0'; i++)
       {
               compare = s1[i] - s2[i];
               if (compare != 0)
                       break;
       }
       return (compare);
}
int  main ()
{
	char *buffer, *token, *salida;
	size_t bufsize = 32;
	size_t characters;
	char delimit[] = " \n";
	char *argv[256];
	int num_words, i, compare;

	num_words = 0;
	i = 0;
	compare = 1;
	salida = "exit\n";
	buffer = malloc(bufsize * sizeof(char));
	if (buffer == NULL)
		return (0);
	while (compare != 0)
	{
		write(1, "$ ", 2);
		characters = getline(&buffer,&bufsize,stdin);
		compare = _strcmp(salida, buffer);
		fork();
		wait(NULL);
		token = strtok(buffer, " \n");
		while (token != NULL)
		{
			argv[i] = token;
			printf("text: %s\n", argv[i]);
			token = strtok(NULL, " \n");
			i++;
		}
		argv[i] = NULL;
		execve(argv[0], argv, NULL);
	}
	/* while (token != NULL) */
	/* { */
	/* 	printf("%s", token); */
	/* 	token = strtok(NULL, " "); */
	/* } */
	return (0);
}
