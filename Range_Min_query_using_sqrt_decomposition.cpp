#include<bits/stdc++.h>
using namespace std;
int n,blk;
int a[1000005];

int getmin(int l,int r,int f[])
{
	int lb=l/blk;
	int rb=r/blk;
	int mn=INT_MAX;
	if(lb==rb)
	{
		for(int i=l;i<=r;i++)
		{
			mn=min(mn,a[i]);
		}
	}
	else
	{
		for(int i=l;i<blk*(lb+1);i++)
		mn=min(mn,a[i]);
		for(int i=lb+1;i<rb;i++)
		mn=min(mn,f[i]);
		for(int i=rb*blk;i<=r;i++)
		mn=min(mn,a[i]);
	}
	return mn;
}
int main()
{
	int q,i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	 blk=ceil(sqrt(n));
	int f[n];
	int feed_pointer = -1; 
	for (int i=0; i<n; i++) 
    { 
        if (i%blk==0) 
        { 
            feed_pointer++; 
            f[feed_pointer]=a[i];
        } 
    
        f[feed_pointer]=min(f[feed_pointer],a[i]); 
    
    } 
	cin>>q;
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		cout<<getmin(l,r,f)<<endl;
	}
}