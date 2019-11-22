#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>


/**
* signalhandler - Ignore CTRL + C.
*
* Return: Nothing.
*/
void signalhandler()
{
       signal(SIGINT, signalhandler);
       write(1, "\n$ ", 3);
}

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
	size_t bufsize = 1024;
	size_t characters;
	char *argv[256];
	int num_words, i, f, exec_status, atty;
	pid_t child_pid;

	i = num_words = 0;
	salida = "exit\n";
	buffer = malloc(bufsize * sizeof(char));
	if (buffer == NULL)
		return (0);
	if (!(atty = isatty(fileno(stdin))))
	{
		printf("is echo");
	}
	else
	{
		while (1)
		{
			write(1, "$ ", 2);
			signal(SIGINT, signalhandler);
			characters = getline(&buffer,&bufsize,stdin);
			if (_strcmp(salida, buffer) == 0)
			{
				free(buffer);
				return (0);;
			}
			if ((child_pid = fork()) == 0)
			{
				token = strtok(buffer, " \n\t");
				while (token != NULL)
				{
					argv[i] = token;
					token = strtok(NULL, " \n\t");
					i++;
				}
				argv[i] = NULL;
				execve(argv[0], argv, NULL);
				kill(getpid(), SIGKILL);
			}
			else
			{
				waitpid(child_pid), exec_status, 0;
			}
		}
	}
	printf("atty %d\n", atty);
	return (0);
}
