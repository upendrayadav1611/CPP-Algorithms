vector<int>vec[10000];
int vis[100000];
void bfs(int src)
{
   queue<int>q;
   q.push(src);
   vis[src]=1;
   dis[src]=0;
   while(!q.empty())
   {
       int curr = q.front();
       q.pop();
       for(int i=0;i<vec[curr].size();i++)
       {
           int child = vec[curr][i];
           if(vis[child]==0)
           {
               vis[child]=1;
               dis[child]=dis[curr]+1;
               q.push(child);
           }
       }
       
   }
}