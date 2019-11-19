#include <stdio.h>
#include <unistd.h>

/**
 * main - fork example
 *
 * Return: Always 0.
 */
int main(void)
{
    /* pid_t my_pid; */
    /* pid_t pid; */

    /* printf("Before fork\n"); */
    /* pid = fork(); */
    /* if (pid == -1) */
    /* { */
    /*     perror("Error:"); */
    /*     return (1); */
    /* } */
    /* printf("After fork\n"); */
    /* my_pid = getpid(); */
    /* printf("My pid is %u\n", my_pid); */
    /* return (0); */
	int i = 3472;
	printf("my process pid is %d\n",getpid());
	pid_t fork_id = fork();
	if (fork_id==0){
		i= 6794;
		printf("child pid %d, i=%d\n",getpid(),i);
	}
	else
		printf("parent pid %d, i=%d\n",getpid(),i);
		return 0;

}
