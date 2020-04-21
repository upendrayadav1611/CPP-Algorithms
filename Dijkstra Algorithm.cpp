#include<bits/stdc++.h>
using namespace std;
int a[10005][10005];
int vis[10005];
int dis[10005];
int findmin(int dis[],int vis[],int n)
{
    int minVertex=-1;
    for(int i=0;i<n;i++)
    {
        if(!vis[i]&&(minVertex==-1||dis[i]<dis[minVertex]))
        {
            minVertex=i;
        }
    }
    return minVertex;
}
void dijkstra(int src,int n)
{
    for(int i=0;i<n;i++)
    {
        dis[i]=INT_MAX;
        vis[i]=0;
    }
    dis[src]=0;
    for(int i=0;i<n;i++)
    {
        int minVertex=findmin(dis,vis,n);
        vis[minVertex]=1;
        for(int j=0;j<n;j++)
        {
            if(a[minVertex][j]!=0&&!vis[j])
            {
                int dist=dis[minVertex]+a[minVertex][j];
                if(dist<dis[j])
                dis[j]=dist;
            }
        }
    }
}
int main()
{
    int n,e,u,v,cost;
    cin>>n>>e;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        a[i][j]=0;
    }
    while(e--)
    {
        cin>>u>>v>>cost;
        a[u][v]=cost;
    }
    dijkstra(0,n);
    for(int i=0;i<n;i++)
    cout<<i<<" "<<dis[i]<<endl;
}