// No of strongly connected components
void fill(vector<int> adj[],int vis[],stack<int> &s,int i)
{
    vis[i]=1;
    for(auto it:adj[i])
    {
        if(!vis[it])
         fill(adj,vis,s,it);
    }
    s.push(i);
}
void dfs(vector<int> g[],int vis[],int i)
{
    vis[i]=1;
    for(auto it:g[i])
    {
        if(!vis[it])
         dfs(g,vis,it);
    }
}
int kosaraju(int V, vector<int> adj[])
{
    // Your code here
    int vis[V],c=0;
    stack<int> s;
    memset(vis,0,sizeof(vis));
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
          fill(adj,vis,s,i);
    }
    vector<int> g[V+1];
    for(int i=0;i<V;i++)
    {
        for(auto it:adj[i])
          g[it].push_back(i);
    }
    memset(vis,0,sizeof(vis));
    while(!s.empty())
    {
        int x=s.top();
        s.pop();
        if(!vis[x])
        {
          dfs(g,vis,x);
          c++;
        }
    }
    return c;
}
