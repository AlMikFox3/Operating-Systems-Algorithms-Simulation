//gcc fname -pthread
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
 

int g = 0;
 

void *myThreadFun1(void *a)
{
	int *p= (int *)a;
    	long sum=0,i;
		for(i=0;i<100;i++)
	{	long k =p[i];
		if(k%2==0)
			sum+=k;
	}
printf("SUM of even numbers%ld\n",sum);
 	

}

void *myThreadFun2(void *a)
{
	int *p= (int *)a;
	int i;
    for(i=0;i<100;i++)
	{	int flag=0,j;
		for(j=2;j<p[i];j++)
		{
			if(p[i]%j==0)
			{flag=1;
			break;}
		}
		if(flag==0)
		{
			printf("%d\n",p[i]);
		}
	}

}
 
int main()
{
    pthread_t tid;
 	time_t t;
	srand((unsigned) time(&t));
	int id,a[100],i;
	for(i=0;i<100;i++)
	{
		a[i]=rand()%101;
	}
 

    pthread_create(&tid, NULL, myThreadFun1,(void*)a);

    pthread_create(&tid, NULL, myThreadFun2,(void*)a);
    
    pthread_exit(NULL);
    return 0; 
}
