#include<stdio.h>
#include<conio.h>
void main()
{
 int a[20],n,i,t=0;
 clrscr();
 printf("Enter head pointer position:");
 scanf("%d",&a[0]);
 printf("\nEnter number of processes:");
 scanf("%d",&n);
 printf("\nEnter processes in request order");
 for(i=1;i<=n;i++)
 {
  scanf("%d",&a[i]);
 }
 for(i=0;i<n;i++)
 {
  if(a[i]<a[i+1])
  t+=(a[i+1]-a[i]);
  else
  t+=(a[i]-a[i+1]);
 }
 printf("\nProcessing order:");
 for(i=0;i<=n;i++)
 printf("\t%d",a[i]);
 printf("\nTotal Head Movement:%d",t);
 getch();
}