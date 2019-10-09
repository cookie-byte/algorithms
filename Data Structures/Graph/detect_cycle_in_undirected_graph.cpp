bool dfs(vector<int> adj[],int vis[],int c,int p)
{
    vis[c]=1;
    for(auto it=adj[c].begin();it!=adj[c].end();++it)
    {
        if(vis[*it]==0)
        {
         if(dfs(adj,vis,*it,c))
          return 1;
        }
        else if(*it!=p)
        {
         return 1; 
        }
    }
    return 0;
}
bool isCyclic(vector<int> adj[], int V)
{
   // Your code here
   int vis[V];
   
    for(int i=0;i<V;i++)
     vis[i]=0;
    for(int i=0;i<V;i++)
    {
     if(vis[i]==0)
       if(dfs(adj,vis,i,-1))
        return 1;
    }
    return 0;
}
