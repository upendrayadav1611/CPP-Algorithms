#include<bits/stdc++.h>
using namespace std;
#define ll long long int
vector<ll>vec[100002];
bool vis[100002];
int in[100002],low[100002];
int timer;
void dfs(ll node,ll par)
{
    vis[node]=true;
    in[node]=low[node]=timer;
    timer++;
    for(ll child:vec[node])
    {
        if(child==par)
        continue;
        if(vis[child]==1)
        {
            // edge node-child is a back edge
            low[node]=min(low[node],in[child]);
        }
        else
        {
            // edge node-child is a forward edge
            dfs(child,node);
            if(low[child]>in[node])
            cout<<node<<"-->"<<child<<" is a bridge\n";
            low[node]=min(low[node],low[child]);
        }
    }
}
int main()
{
    ll n,m,x,y;
    cin>>n>>m;
    while(m--)
    {
        cin>>x>>y;
        vec[x].push_back(y);
        vec[y].push_back(x);
        dfs(1,-1);
    }
}
