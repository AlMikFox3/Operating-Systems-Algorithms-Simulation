#include<stdio.h>
void swap (int *a , int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int main()
{
	int a[20],d[20],b[20],w[20],tat[20],p[20];
	int n,temp,temp1,temp2;
	printf("Enter the no. of processes : ");
	scanf("%d",&n);
	int i,j;
	for(i = 0;i<n;i++)
	{
		printf("Enter arr time for p[%d] : ",i+1);
		scanf("%d",&a[i]);
		printf("Enter burst time for p[%d] : ",i+1);
		scanf("%d",&b[i]);
		p[i] = i+1;
	}
	/*for(i = 0;i< n; i++)
	{
		for(j=i+1; j<n; j++)
		{
			if(a[i]>a[j])
			{
				swap(&a[i],&a[j]);
				swap(&b[i],&b[j]);
				swap(&p[i],&p[j]);
			}
		}
	}*/
	for(i=1;i<=n-1;i++)
    	{
        	temp=p[i];
		temp1=a[i];
		temp2=b[i];
        	j=i-1;
 
        	while((temp1<a[j])&&(j>=0))
        	{
            	p[j+1]=p[j];    //moves element forward
		a[j+1]=a[j];
		b[j+1]=b[j];
            	j=j-1;
       	 }
 
        p[j+1]=temp;    //insert element in proper place
	a[j+1]=temp1;
	b[j+1]=temp2;
    }
	
	for(i = 0;i<n;i++)
	{
		d[i] = 0;		
		for(j=0;j<i;j++)
		{
			d[i] += b[j];
		}
		w[i] = d[i]-a[i];
		tat[i] = w[i] + b[i];	
	}
	float sum=0,sum1=0;
	printf("process\t\tarrival\t\tturn around time\t\twait\n");	
	for(i = 0; i<n;i++)
	{
		printf("p[%d]\t\t%d\t\t%d\t\t\t%d\n",p[i],a[i],tat[i],w[i]);
		sum += w[i];
		sum1 += tat[i];
	}
	printf("\nAWT%f",sum/n);
	printf("\nATAT%f",sum1/n);

	
				
	
}	
		
		
