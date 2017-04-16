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
	int frame,pf=0;
	cin>>frame;
	int a[11],b[10],k=0,c[frame];
	for(int i=0;i<frame;i++)
	{
		c[i]=0;
	}
	memset(b,0,sizeof(b));
	for(int i=0;i<11;i++)
		cin>>a[i];
	int j=0;
	for(int i=0;i<11;i++)
	{
		if(b[a[i]]==0)
				{	b[a[i]]=1;
					pf++;
					int l=j++%frame;
					b[c[l]]=0;
					c[l]=a[i];
					
							print(c,frame);
			}
	}
	cout<<j<<"\n";
	cout<<"Number of page faults "<<pf<<"\n";
	return 0;
}