#include <bits/stdc++.h>
using namespace std;
int search(int ele, int frame[],int ref[], int* full)
{
    int i,flag;
    flag=0;
    if(*full!=0)
    {
        for(i=0;i<*full;i++)
           if(ele==frame[i])
            {   
                flag=1;ref[i]=1;
                break;
            }   
        }
    return flag;   
}
/*void print(int *c,int frame)
{
for(int i=0;i<frame;i++)
    cout<<c[i]<<" ";
cout<<"\n";
}*/
int  maxi(int *c,int frame)
{   int m=-1,k;
    for(int i=0;i<frame;i++){
        if(c[i]>m)
            {k=i;
            m=c[i];
        //  cout<<k<<"\n";  
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
int FIFO(int *a, int n, int SIZE)
{
    int pf=0;
    int size = n;
    int frame = SIZE;
    int b[7],k=0,c[frame];
    for(int i=0;i<frame;i++)
    {
        c[i]=0;
    }
    memset(b,0,sizeof(b));
    /*int randn;
    srand((unsigned)time(0));
    for(int i=0;i<size;i++)
    {
        randn = (rand()%8 + 1);
        a[i] = randn;
        cout<<a[i]<<" ";
    }*/
    int j=0;
    for(int i=0;i<size;i++)
    {
        if(b[a[i]]==0)
                {   b[a[i]]=1;
                    pf++;
                    int l=j++%frame;
                    b[c[l]]=0;
                    c[l]=a[i];
                            //cout<<"\n";
                            //print(c,frame);
            }
    }
    return pf;
}
int LRU(int* a, int n, int SIZE)
{
    int frame = SIZE, pf=0, size=n;
    int b[9],k=0,c[frame],pri[frame];
    memset(b,0,sizeof(b));
    /*int randn;
    srand((unsigned)time(0));
    for(int i=0;i<size;i++)
    {
        randn = (rand()%8+1);
        a[i] = randn;
        cout<<randn<<" ";
    }*/
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
    //  cout<<c[i]<<" ";
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
                   // print(c,frame);

    }
    return pf;
}
int main()
{   int SIZE,n;
    cin>>SIZE;
    cin>>n;
    int full=0;
    int ref[SIZE];
    int frame[SIZE];
    int repptr=0;
    int count=0;
    int randn;
    int a[n];
    srand((unsigned)time(0));
    for(int i=0;i<n;i++)
    {
        randn = (rand()%6 + 1);
        a[i] = randn;
        cout<<a[i]<<" ";
    }
   // int a[18] = {0,4,1,4,2,4,3,4,2,4,0,4,1,4,2,4,3,4};
   // for(i=0;i<n;i++)
   // printf("%d  ",a[i]);
    //printf("\n\n");
    for(int i=0;i<n;i++)
    {
        if(search(a[i],frame,ref, &full)!=1)
            {   if(full!=SIZE)
                {
                    ref[full]=1;
                    frame[full++]=a[i];
                }
                else
                {
                    int temp;
                    while(ref[repptr]!=0)
                    { 
                        ref[repptr++]=0;
                        if(repptr==SIZE)
                            repptr=0;
                    }                     
                    temp=frame[repptr];
                    frame[repptr]=a[i];
                    ref[repptr]=1;
                }
                for(int i=0;i<full;i++)
                    cout<<frame[i]<<" ";
                count++;
                cout<<"\n";
            }
    }
    cout<<"Page Fault Count (Second Chance) = "<<count;
    int count1 = LRU(a,n,SIZE);
    cout<<"\nPage Fault Count (LRU) = "<<count1;
    int count2 = FIFO(a,n,SIZE);
    cout<<"\nPage Fault Count (FIFO) = "<<count2;
    
return 0;
}