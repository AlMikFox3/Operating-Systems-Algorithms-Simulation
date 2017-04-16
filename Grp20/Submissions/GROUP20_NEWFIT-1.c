/*Testcase Considered
Block size  
50
200
70
115
15
Rest info as given in question

Output
1 	2	5	5	5
2	4		
3	3	3
4	1	1	1
5
*/

#include <stdio.h>
int check(int *a,int n)
{int i;
	for(i=0;i<n;i++)
		if(a[i]!=0)
			return 1;
	return 0	;
}
int main()
{
	int i,j,l,size[5],ta[5],block[5],no[5]={0,0,0,0,0},noj[5]={0,0,0,0,0};
	int shared[5],hai[2]={0,0};
	for(i=0;i<5;i++)
		scanf("%d",&size[i]);
	for(i=0;i<5;i++)
		scanf("%d",&ta[i]);
	for(i=0;i<5;i++)
		scanf("%d",&block[i]);
	for(i=0;i<5;i++)
		scanf("%d",&shared[i]);
	int k=10;
	do
	{	for(i=0;i<5;i++)
		{	

			if(size[i]==0)
				{
						//printf("%d k\n",i);
					continue;}
			if(hai[shared[i]-1]>1)
						{ int temp[5],k=0;
							for(j=0;j<5;j++)
							{//printf("%d j\n",j);
								if(no[j]>0)
								continue;
							if(size[i]<block[j])
								{
									//printf("%d %d\n",i,j);
									temp[k++]=j;
								}
								}

							if(k==1)
							{
								no[j]=ta[i];
						noj[j]=i+1;
						size[i]=0;
						hai[shared[i]-1]=+1;
							}
							else if(k>1)
							{
								int flag=1,m=1;
								while(flag && m<3)
								{
									for(l=0;l<k;l++)
									{
										if((temp[l]-m)>=0 && no[temp[l]-m]>0)
										{ 
											if(shared[noj[temp[l]-m]-1]==shared[i])
													{flag=0;
														break;
													}

										}
										else if((temp[l]+m)<5 && no[temp[l]+m]>0)
										{
											if(shared[noj[temp[l]-m]-1]==shared[i])
												{flag=0;
													break;
												}
												
										}
									}
									if(flag==0)
									{
										no[temp[l]]=ta[i];
										noj[temp[l]]=i+1;
										size[i]=0;
										hai[shared[i]-1]=+1;
										break;
									}
									m++;
								}
							}
							}
			else
			{
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
						hai[shared[i]-1]=+1;
			}		
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
		

		}while(check(noj,5));
	return 0;
}