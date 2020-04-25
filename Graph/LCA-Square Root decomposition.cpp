// LCA using square root decomposition
// Time complexity of this method is O(sqrt(height)

#include<bits/stdc++.h>
using namespace std;
int blk;
int par[100005],jump_par[100005],level[100005],vis[100005],depth[100005];
vector<int>vec[100005];
void dfs_for_depth(int v)
{
    vis[v]=1;
    for(int i=0;i<vec[v].size();i++)
    {   
        int child=vec[v][i];
        if(vis[child]==0)
        {   
            depth[child]=depth[v]+1;
            dfs_for_depth(child);
        }
            
    }
}

void dfs(int v,int p)
{
    par[v]=p;
    level[v]=level[p]+1;
    if(level[v]%blk==0)
    {
        jump_par[v]=par[v];
    }
    else
    {
        jump_par[v]=jump_par[p];
    }
    for(int i=0;i<vec[v].size();i++)
    {
        int child=vec[v][i];
        if(child!=p)
        dfs(child,v);
    }
}
int LCAnaive(int a,int b)
{
    if(level[a]>level[b])
    {
        swap(a,b);
    }
    int d=level[b]-level[a];
    while(d>0)
    {
        b=par[b];
        d--;
    }
    if(a==b)
    return a;
    while(par[a]!=par[b])
    {
        a=par[a];
        b=par[b];
    }
    return par[a];
}
int SRDlca(int u,int v)
{
    while (jump_par[u] != jump_par[v]) 
    { 
        if (level[u] > level[v])
            swap(u,v);
        v = jump_par[v]; 
    } 
    return LCAnaive(u,v); 
}
void preprocessing(int height)
{
    blk=sqrt(height);
    level[1]=-1;
    dfs(1,-1);
    
}
int main()
{
    int n,m,i,u,v;
    cin>>n>>m;
    while(m--)
    {
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    depth[1]=0;
    dfs_for_depth(1);
    int height=*max_element(depth,depth+n);
    preprocessing(height);
    cout<<SRDlca(11,8)<<"\n";
    cout<<SRDlca(3,13)<<"\n";
    return 0;
}