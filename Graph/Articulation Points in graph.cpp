#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
vector<ll>vec[100001];
bool vis[100001];
ll in_time[100001],low[100001];
int timer;//children is to calculate number od child root vertex has
                    //If root has more than one child then it is articulation point
set<ll>st;///set to store articulation points
ll min(ll a,ll b)
{
    if(a<b)
    return a;
    return b;
}
void dfs(ll node,ll p)
{
    vis[node]=true;
    in_time[node]=low[node]=timer;
    timer++;
    ll children=0;
    for(ll child:vec[node])
    {
        if(child==p)
        continue;
        if(vis[child]==true)
        {
            low[node]=min(low[node],in_time[child]);
        }
        else
        {
            dfs(child,node);
            low[node]=min(low[node],low[child]);
            if(low[child]>=in_time[node]&&p!=-1)
            {
                st.insert(node);
            }
            
            ++children;
        }
    }
    if(p==-1&&children>1)
        st.insert(node);
}
int main()
{
    ll n,m;
    ll x,y;
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        vis[i]=false;
        in_time[i]=-1;
        low[i]=-1;
        vec[i].clear();
        st.clear();
        
    }
    while(m--)
    {
        
        cin>>x>>y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    timer=0;
    for(ll i=1;i<=n;i++)
    {   
        if(vis[i]==false)
        dfs(i,-1);
    }
    cout<<st.size()<<"\n";
}