#include <bits/stdc++.h>
using namespace std;
int main()
{
	int at[20],bt[20],rt[20],wt[20],tat[20],s;
	int n;
	cin>>n;
	int remain = 0;
	for(int i=1;i<=n;i++)
	{
		cin>>at[i];
		cin>>bt[i];
		rt[i] = bt[i];
	}
	int time = 0,et;
	rt[15] = 999;
	for(time = 0;remain != n; time++)
	{
		s = 15;
		for(int i=1;i<=n;i++)
		{
			if(at[i]<=time && rt[i]<rt[s] && rt[i] > 0)
			{
				s = i;
			}
		}
		rt[s]--;
		cout <<s<<"\n";
		if(rt[s] == 0)
		{
			remain++;
			et = time+1;
			cout<<s<<"   "<<et-at[s]<<"   "<<et-bt[s]-at[s];
			cout<<endl;
		}
	}
	return 0;
}