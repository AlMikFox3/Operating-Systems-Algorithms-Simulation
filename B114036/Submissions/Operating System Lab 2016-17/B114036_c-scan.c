#include<iostream.h>
#include<conio.h>
void scan(int left[],int right[],int i,int head,int n)
{
int ans[20];
int a,b,c,d;
a=i-1;
d=0;
c=n-1-i;
b=i;
while(a>-1)
{ cout<<“\n a is “<<a;
cout<<“\n left[a] is”<<left[a];

ans[d]=left[a];
cout<<“\n answer is”<<ans[d];
a–;
d++;
}
cout<<“d is”<<d;
while(d<n)
{
ans[d]=right[c];
cout<<“\n right c is”<<right[c];
cout<<“\n ans[d] is “<<ans[d];
c–;
d++;
}
cout<<“order is”;
getch();
for(int j=0;j<n;j++)
{
cout<<“\n”<<ans[j];
}
}
void divide(int d[],int n,int head)
{
cout<<“array is”;
for(int q=0;q<n;q++)
{
cout<<“\n “<<d[q];
}
int left[10],right[10];
for(int i=0;i<n;i++)
{
if(d[i]>head)
{
cout<<“breaking at “<<d[i];
break;
}
}
cout<<“value of i”<<i;
int k,l,m;
l=1;
k=0;
m=n;
left[0]=d[0];
cout<<“left is”<<left[0];
while(l<i)
{
cout<<“\n d[l] value” <<d[l];
left[l]=d[l];
cout<<“\n left is “<<left[l];
l++;
cout<<“l is “<<l;
}
int o;
o=i;
while(o<m)
{
right[k]=d[o];
cout<<“\n right is”<<right[k];
cout<<“\n d[i] is”<<d[o];
k++;
o++;
}
scan(left,right,i,head,n);
}
void sort(int d[],int n)
{
int temp,small,pos;
for(int i=0;i<n-1;i++)
{
small=d[i];
pos=i;
for(int j=i+1;j<n;j++)
{
if(small>d[j])
{
small=d[j];
pos=j;
}
}
temp=d[pos];
d[pos]=d[i];
d[i]=temp;
}
}
void main()
{
clrscr();
int head,d[20],n;
cout<<” enter number of disk schedulings you want to do”;
cin>>n;
cout<<“enter head”;
cin>>head;
for(int i=0;i<n;i++)
{
cout<<“\n enter”;
cin>>d[i];
}
sort(d,n);
divide(d,n,head);
getch();
}