// Output will be V space separated integers where the ith integer denote the shortest distance of ith vertex from given source vertex.
int minkey(int V,bool mst[],int key[])
{
    int min=INT_MAX,minin;
    for(int i=0;i<V;i++)
    {
        if(!mst[i] && key[i]<min)
         min=key[i],minin=i;
    }
    return minin;
}
void dijkstra(vector<vector<int>> graph, int src, int V)
{
    // Your code here
    bool mst[V];
    int key[V];
    for(int i=0;i<V;i++)
     mst[i]=false,key[i]=INT_MAX;
    key[src]=0;
    for(int i=0;i<V-1;i++)
    {
        int u=minkey(V,mst,key);
        mst[u]=true;
        for(int v=0;v<V;v++)
        {
            if(graph[u][v] && !mst[v] && key[u]+graph[u][v]<key[v])
             key[v]=key[u]+graph[u][v];
        }
    }
    for(int i=0;i<V;i++)
     cout<<key[i]<<" ";
}
