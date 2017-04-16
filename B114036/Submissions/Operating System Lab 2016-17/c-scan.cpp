#include <bits/stdc++.h>
using namespace std;
int find(int *a, int ele, int n)
{
	for(int i=0;i<n;i++)
		if(a[i]==ele)
			return i;
}
int main()
{
	int a[20],n,b[20];
	a[0] = 0;
	int sum=0;
	cin>>n;
	for(int i=1;i<n-2;i++)
	{
		cin>>a[i];
	}
	cin>>a[n-2];
	int head = a[n-2];
	a[n-1]=199;
	for(int i=0;i<n;i++)
	{
		int small = i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[small])
			{
				small = j;
			}
		}
		if(small!=i)
		{
			int temp = a[small];
			a[small] = a[i];
			a[i] = temp;
		}
	}
	int mid = 199/2;
	int k=0;
	if(head<mid)
	{
		int p = find(a,head, n);
		int q = p;
		for(p;p>0;p--)
		{
			sum += a[p] - a[p-1];
			b[k++]= a[p];
			cout<<"\n"<<a[p]<<"-"<<a[p-1];
		}
		b[k++]=a[p]; int t;
		for(t=n-1;t>q+1;t--)
		{
			sum += a[t] - a[t-1];
			b[k++]=a[t];
			cout<<"\n"<<a[t]<<"-"<<a[t-1];
		}
		b[k++]=a[t];
	}
	else
	{
		int p = find(a,head,n); int t;
		int q = p;
		for(p;p<n-1;p++)
		{
			sum += a[p+1] - a[p];
			b[k++]=a[p];
		}
		b[k++]=a[p];
		for(t=0;t<q-1;t--)
		{
			sum += a[t+1] - a[t];
			b[k++]= a[t];
		}
		b[k++]=a[t];
	}
	for(int i = 0;i<n;i++)
		cout<<b[i]<<"  ";
	cout<<endl<<sum;

	return 0;
}
