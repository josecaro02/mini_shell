#include "header.h"
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

int exit_func (char **argv)
{
	char *salida;
	int num_exit;

	salida = "exit\n";
	if (_strcmp(salida, argv[0]) == 0)
	{
		if (argv[1] != NULL)
		{
			num_exit = _atoi(argv[1]);
			if (num_exit < 0)
				exit(0);
			else if (num_exit <= 255)
				exit(num_exit);
			else
				exit(num_exit % 255);

		}
		exit(0);
	}
	return (0);
}

void excess_argv(char *argv0, char *argv1)
{
	char *text = ": 0: Can't open ";
	char *text2 = "\n";
 	write(1, argv0, _strlen_recursion(argv0));
	write(1, text, _strlen_recursion(text));
	write(1, argv1, _strlen_recursion(argv1));
	write(1, text2, 1);
	exit(127);

}
int  main (int argc, char *argum[])
{
	char *buffer, *token;
	size_t bufsize = 1024;
	char *argv[256];
	int i, j, exec_status, atty, characters;
	pid_t child_pid;

	if (argc > 1)
		excess_argv(argum[0],argum[1]);
	i = atty = 0;
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
		for ()
		{}
		token = strtok(buffer, " \n\t");
		while (token != NULL)
		{
			argv[i] = token;
			token = strtok(NULL, " \n\t");
			i++;
		}
		argv[i] = NULL;
		printf("characters: %d\n", characters);
		if (characters == -1)
		{
			free (buffer);
			return (0);
		}
		exit_func(argv);
		if ((child_pid = fork()) == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
				perror("Error");
			kill(getpid(), SIGKILL);
		}
		else
			waitpid((child_pid), &exec_status, 0);
		for (j = 0; j < i ; j++)
			argv[i] = NULL;
		i = 0;
	}
	return (0);
}
