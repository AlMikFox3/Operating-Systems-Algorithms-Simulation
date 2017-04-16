#include <stdio.h>
int check(int *a,int n)
{int i;
	for(i=0;i<n;i++)
		if(a[i]!=0)
			return 1;
	return 0	;
}
int main()
{	//no - turn around  | noj - job in frame
	int i,j,size[10],ta[10],bkmlock[5],no[5]={0,0,0,0,0},noj[5]={0,0,0,0,0};
	for(i=0;i<10;i++)
		scanf("%d",&size[i]);
	for(i=0;i<10;i++)
		scanf("%d",&ta[i]);
	for(i=0;i<5;i++)
		scanf("%d",&block[i]);
	int k=10;
	while(check(size,10))
	{	for(i=0;i<10;i++)
		{	if(size[i]==0)
				{
						//printf("%d k\n",i);
					continue;}
			int min=1000,idx=-1;
			for(j=0;j<5;j++)
				{//printf("%d j\n",j);
					if(no[j]>0)
					continue;
				if(size[i]<block[j] && min>block[j])
					{
						//printf("%d %d\n",i,j);
						idx=j;
						min=block[j];
					}
					}
			if(idx!=-1)
			{
				no[idx]=ta[i];
						noj[idx]=i+1;
						size[i]=0;
			}		
		}

		for(i=0;i<5;i++)
			printf("%d ",noj[i]);
		printf("\n");
		for(j=0;j<5;j++)
			if(no[j]>0)
				{no[j]--;
					if(no[j]==0)
						noj[j]=0;
				}

		}
	return 0;
}