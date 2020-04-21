// BFS implementation on grid for shortest path from source node to all other nodes

#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
char ch[1005][1005];
bool vis[1005][1005];
int dis[1005][1005];
int rowNum[] = {-1, 0, 0, 1}; 
int colNum[] = {0, -1, 1, 0}; 
int n,m;
bool isValid(int row, int col) 
{ 
    // return true if row number and column number 
    // is in range 
    return (row >= 1) && (row <=n) && 
           (col >= 1) && (col <= m); 
} 
void bfs(pair<int,int>a)
{
    //if(ch[a.fi][a.se]=='*'||ch[b.fi][b.se]=='*')
    //return -1;
    memset(vis,false,sizeof(vis));
    memset(dis,0,sizeof(dis));
    vis[a.fi][a.se]=true;
    queue<pair<pair<int,int>,int>>q;
    q.push({a,0});
    while(!q.empty())
    {
        pair<pair<int,int>,int>p=q.front();
        q.pop();
        dis[p.fi.fi][p.fi.se]=p.se;
        for (int i = 0; i < 4; i++) 
        { 
            int row = p.fi.fi + rowNum[i]; 
            int col = p.fi.se + colNum[i]; 
              
            // if adjacent cell is valid, has path and 
            // not visited yet, enqueue it. 
            if (isValid(row, col) && ch[row][col]!='*' &&  
               !vis[row][col]) 
            { 
                // mark cell as visited and enqueue it 
                vis[row][col] = true; 
                //queueNode Adjcell = { {row, col}, 
                                      //curr.dist + 1 }; 
                q.push({{row,col},p.se+1}); 
            } 
        } 

    }
    
}
int main()
{
    int q,i,j,s,d,x,y;
    cin>>n>>m>>q;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cin>>ch[i][j];
        }
    }
    cin>>s>>d;
    bfs({s,d});
    while(q--)
    {
        cin>>x>>y;
        if(ch[x][y]=='*'||!vis[x][y])
        cout<<-1<<"\n";
        else
        cout<<dis[x][y]<<"\n";
    }


}