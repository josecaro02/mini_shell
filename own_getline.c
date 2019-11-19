#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
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
/**
* get_line - prompt.
* @buffer: Buffer.
* @size: Size.
*
* Return: Always 0.
*/
ssize_t get_line(char **buffer, size_t *size)
{
       ssize_t re_prompt;
       char prompts[2];
       char *salida;
       int compare, f;

       compare = 1;
       salida = "exit\n";
       while (compare != 0)
       {
               prompts[0] = '$';
               prompts[1] = ' ';
               write(1, prompts, 2);
	       signal(SIGINT, signalhandler);
               re_prompt = read(STDIN_FILENO, *buffer, *size);
               if (!re_prompt)
               {
                       return (0);
               }
	       compare = _strcmp(salida, *buffer);
	       for (f = 0; buffer[0][f] != '\0'; f++)
		       buffer[0][f] = '\0';
       }
       return (0);
}
/**
* main - prompt.
*
* Return: Always 0.
*/
int main(void)
{
       char *buffer;
       size_t size = 1024;
       unsigned int i, f;

       buffer = malloc(sizeof(char) * 1024);
       for (f = 0; f < 1024; f++)
               buffer[f] = '\0';
       get_line(&buffer, &size);
       i = 0;
       while (buffer[i] != '\0')
       {
               putchar(buffer[i]);
               i++;
       }
       free(buffer);
       return (0);
}
