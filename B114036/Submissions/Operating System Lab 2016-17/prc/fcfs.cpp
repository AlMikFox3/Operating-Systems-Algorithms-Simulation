#include <bits/stdc++.h>
using namespace std;
int main()
{
	int at[10],bt[10],s,d[10],w[10],tat[10];
	for(int i=0;i<5;i++)
	{
		cin>>at[i];
		cin>>bt[i];
	}
	for(int i=0;i<5;i++)
	{
		s = i;
		for(int j = i+1;j<5;j++)
		{
			if(at[j]<at[s])
			{
				s = j;
			}
		}
		if(s!=i)
		{
			int temp = at[i];
			at[i] = at[s];
			at[s] = temp;
			temp = bt[i];
			bt[i] = bt[s];
			bt[s] = temp;
		}
	}
	for(int i=0;i<5;i++)
		cout<<at[i];
	for(int i = 0;i<5;i++)
	{
		d[i] = 0;		
		for(int j=0;j<i;j++)
		{
			d[i] += bt[j];
		}
		w[i] = d[i]-at[i];
		tat[i] = w[i] + bt[i];	
	}
	cout<<endl;
	for(int i = 0; i<5;i++)
	{
		cout<<i<<"   "<<at[i]<<"   "<<tat[i]+1<<"   "<<w[i]+1<<"\n";
	}
}