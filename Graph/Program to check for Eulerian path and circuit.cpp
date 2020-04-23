#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define pb push_back
ll n,m;
vector<ll>vec[100004];
bool vis[100004];

void dfs(ll v)
{
    vis[v]=true;
    for(ll child: vec[v])
    {
        if(!vis[child])
        dfs(child);
    }
}

bool isconnected()
{
    ll i;
    for(i=1;i<=n;i++)
    vis[i]=false;
    
    for(i=1;i<=n;i++)
    {
        if(vec[i].size()!=0)
        break;
    }
    if(i==n+1)
    return true;
    dfs(i);
    
    for(ll i=1;i<=n;i++)
    {
        if(vis[i]==false&&vec[i].size()>0)
        return false;
    }
    return true;
    
}

int isEulerian()
{
    ll odd=0;
    if(isconnected()==false)
    return 0;
    for(ll i=1;i<=n;i++)
    {
        if(vec[i].size()&1)           //This is to claculate number of vertices with odd degree
        odd++;
    }
    
    if(odd>2)
    return 0;
    
    if(odd==2)
    return 1; // graph contains Eulerian path
    if(odd==0)
    return 2; // graph contains Eulerian Circuit
}
int main()
{
    ll x,y;
    cin>>n>>m;
    while(m--)
    {
        cin>>x>>y;
        vec[x].pb(y);
        vec[y].pb(x);
    }
    if(isEulerian()==0)
    cout<<"Graph is not Eulerian"<<"\n";
    else if(isEulerian()==1)
    cout<<"Graph has Eulerian path"<<"\n";
    else
    cout<<"Graph has Eulerian Circuit"<<"\n";
    
}