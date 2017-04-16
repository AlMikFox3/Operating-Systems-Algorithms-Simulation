#include <bits/stdc++.h>
using namespace std;
void print(int *c,int frame)
{
for(int i=0;i<frame;i++)
	cout<<c[i];
cout<<"\n";
}
int main()
{
	int frame,pf=0,size;
	cin>>frame;
	cin>>size;
	int a[size],b[9],k=0,c[frame];
	for(int i=0;i<frame;i++)
	{
		c[i]=0;
	}
	memset(b,0,sizeof(b));
	int randn;
	srand((unsigned)time(0));
	for(int i=0;i<size;i++)
	{
		randn = (rand()%8 + 1);
		a[i] = randn;
		cout<<a[i]<<" ";
	}
	int j=0;
	for(int i=0;i<size;i++)
	{
		if(b[a[i]]==0)
				{	b[a[i]]=1;
					pf++;
					int l=j++%frame;
					b[c[l]]=0;
					c[l]=a[i];
							cout<<"\n";
							print(c,frame);
			}
	}
	//cout<<j<<"\n";
	cout<<"Number of page faults "<<pf<<"\n";
	return 0;
}