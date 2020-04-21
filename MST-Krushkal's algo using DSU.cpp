#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll par[100005],r[100005];
struct edge{
    int a,b,w;
};
edge ar[200005];
bool comp(edge a,edge b)
{
    return a.w<b.w;
}
ll find(ll a)
{
    if(par[a]<0)
    return a;
    return par[a]=find(par[a]);
}
void merge(ll a,ll b)
{	
	if(r[a]>r[b])
	{
		par[b]=a;
		r[a]+=r[b];
	}
	else
	{
		par[a]=b;
		r[b]+=r[a];
	}
    
}
int main()
{
    ll n,m,i,a,b,t;
    cin>>t;
    while(t--)
    {
	    cin>>n>>m;
	    for(i=1;i<=n;i++)
	    {
	        par[i]=-1;
	       
	    }
	    for(i=0;i<m;i++)
	    cin>>ar[i].a>>ar[i].b>>ar[i].w;
	
	    sort(ar,ar+m,comp);
	    ll sum=0;
	    for(i=0;i<m;i++)
	    {
	        a=find(ar[i].a);
	        b=find(ar[i].b);
	        if(a!=b)
	        {
	            sum=sum+ar[i].w;
	            merge(a,b);
	        }
	    }
	    cout<<sum<<"\n";
    }
}