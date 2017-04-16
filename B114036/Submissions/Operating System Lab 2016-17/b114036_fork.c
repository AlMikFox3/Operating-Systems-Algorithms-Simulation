#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	time_t t;
	srand((unsigned) time(&t));	
	int ra[100], sum = 0, i, j;
	for(i=0;i<100;i++)
	{
		ra[i] = rand()%101;
	}	
	int id; // int w = 2;
	id = fork();
	if(id > 0)
	{
		//wait(&w);
		//Since the parent process ends before the child process...
		//printf("Parent process ID = %d\n", getpid());
		wait();
		for(i=0;i<100;i++)
		{
			if(ra[i]%2==0)
				sum += ra[i];
		}
		printf("Parent Sum (of even nos)  = %d\n", sum);
	}
	else if(id == 0)
	{
		printf("Child PID = %d\n", getpid());
		printf("Parent ID = %d\n", getppid());
		//execlp("/bin/ps","ps",NULL);//Executing commands inside bin
		for(i=0;i<100;i++)
		{	int f =0 ;
			for(j = 2; j<ra[i]/2; j++)
			{
				if(ra[i]%j == 0)
				{	f = 1;
					break;
				}
			}if(!f)
				printf("%d\n",ra[i]);	
			}
		
	}
	else
	{
		printf("Fork Failed :(");
	}
	return 0;
}
