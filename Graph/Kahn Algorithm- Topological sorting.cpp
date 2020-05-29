#include<bits/stdc++.h>
using namespace std;
vector<int>vec[100005];
vector<int>res;
int in[100005];
void Kahn(int n)
{
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        if(in[i]==0)
        q.push(i);
    }
    while(!q.empty())
    {
        int cur=q.front();
        q.pop();
        res.push_back(cur);
        for(int node:vec[cur])
        {
            in[node]--;
            if(in[node]==0)
            q.push(node);
        }
    }
    for(int i=0;i<res.size();i++)
    cout<<res[i]<<" ";
    cout<<"\n";
}



int main()
{
    int n,m,x,y;
    cin>>n>>m;
    while(m--)
    {
        cin>>x>>y;
        vec[x].push_back(y);
        in[y]++;
    }
    Kahn(n);
    return 0;
    
}