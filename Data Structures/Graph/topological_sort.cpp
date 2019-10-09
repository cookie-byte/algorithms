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
int* topoSort(int V, vector<int> adj[])
{
    // Your code here
    stack<int> s;
    int *res=(int*)malloc(sizeof(int)*V);
    int k=0;
    int vis[V];
    memset(vis,0,sizeof(vis));
    for(int i=0;i<V;i++)
     if(!vis[i])
      fill(adj,vis,s,i);
    while(!s.empty())
    {
        int x=s.top();
        s.pop();
        res[k]=x;
        k++;
    }
    return res;
}

