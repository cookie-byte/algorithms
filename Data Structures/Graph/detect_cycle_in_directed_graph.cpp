bool dfs(vector<int> adj[],int vis[],int ts[],int c)
{
    if(!vis[c])
    {
      ts[c]=1;
      vis[c]=1;
        for(auto i : adj[c])
        {
            if(!vis[i] && dfs(adj,vis,ts,i))
               return 1;
            else if(ts[i]==1)
               return 1;
        }
    }
    ts[c]=0;
    return 0;
}
bool isCyclic(int V, vector<int> adj[])
{
    // Your code here
    int vis[V]={0},ts[V]={0};
    for(int i=0;i<V;i++)
    {
        if(vis[i]==0)
          if(dfs(adj,vis,ts,i))
            return 1;
    }
    return 0;
}
