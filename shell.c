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

int exit_func (char *argv[])
{
	/* salida = "exit\n"; */
	printf("exit func:%s\n",argv[0]);
	return (0);
}
int  main ()
{
	char *buffer, *token, *salida;
	size_t bufsize = 1024;
	int characters;
	char *argv[256];
	int i, exec_status, atty;
	pid_t child_pid;

	i = atty = 0;
	salida = "exit\n";
	buffer = malloc(bufsize * sizeof(char));
	if (buffer == NULL)
		return (0);
	if (!(isatty(fileno(stdin))))
		atty = 1;
	while (1)
	{
		if (atty == 0)
			write(1, "$ ", 2);
		signal(SIGINT, signalhandler);
		characters = getline(&buffer,&bufsize,stdin);
		if (characters == -1)
		{
			free (buffer);
			return (0);
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
			exit_func (argv);
			if (_strcmp(salida, argv[0]) == 0)
			{
				free(buffer);
				return (0);
			}
			if (execve(argv[0], argv, NULL) == -1)
				perror("Error");
			kill(getpid(), SIGKILL);
		}
		else
		{
			waitpid((child_pid), &exec_status, 0);
		}
	}
	return (0);
}
