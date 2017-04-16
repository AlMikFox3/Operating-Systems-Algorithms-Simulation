#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int fd[2], nbytes;
	pid_t childpid;
	char string[20];
	scanf("%[^\n]",string);
	char rbuf[80];

	pipe(fd);
	if((childpid = fork()) == -1)
	{
		perror("fork");
		exit(1);
	}
	if(childpid == 0)
	{
		close(fd[0]);
		write(fd[1], string, (strlen(string)+1));
		exit(0);
	}
	else
	{
		close(fd[1]);
		nbytes = read(fd[0], rbuf, sizeof(rbuf));
		printf("Received Command : %s", rbuf);		
		system(rbuf);		
	}
	return 0;
}
		 
