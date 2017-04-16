#include <bits/stdc++.h>
using namespace std;
void print(int *c,int frame)
{
for(int i=0;i<frame;i++)
	cout<<c[i]<<" ";
cout<<"\n";
}
int  maxi(int *c,int frame)
{	int m=-1,k;
	for(int i=0;i<frame;i++){
		if(c[i]>m)
			{k=i;
			m=c[i];
		//	cout<<k<<"\n";	
		}
		if(c[i]==-1)
			return i;
	}
	return k;		
}
void update(int *p,int frame,int* cf)
{
	for(int i=0;i<frame;i++){
		if(cf[i] != -1)
			p[i]++;
	}
}
int main()
{	
	int frame,pf=0,size;
	cin>>frame;
	cin>>size;
	int a[size],b[9],k=0,c[frame],pri[frame];
	memset(b,0,sizeof(b));
	int randn;
	srand((unsigned)time(0));
	for(int i=0;i<size;i++)
	{
		randn = (rand()%8+1);
		a[i] = randn;
		cout<<randn<<" ";
	}
	int j=0;
	for(int i=0;i<frame;i++)
	{
		c[i]=-1;
	}
	//for(int i=0;i<frame;i++)
		//c[j++]=a[i];
	for(int i=0;i<frame;i++)
		pri[i]=-1;
	//for(int i=0;i<frame;i++)
	//	cout<<c[i]<<" ";
	cout<<"\n";
	for(int i=0;i<size;i++)
	{
		if(b[a[i]]==0)
				{	
					pf++;
					int p=maxi(pri,frame);
					b[c[p]]=0;
					b[a[i]]=1;
					c[p]=a[i];
					//cout<<"maxi"<<p<<"\n";
					update(pri,frame,c);	
					pri[p]=0;
			}
			else
			{
				update(pri,frame,c);
				for(int j=0;j<frame;j++)
					if(c[j]==a[i])
						pri[j]=0;

			}
					print(c,frame);

	}
	cout<<"Number of page faults "<<pf<<"\n";
	return 0;
}
