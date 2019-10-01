// Function to construct and print MST for
// a graph represented using adjacency
// matrix representation, with V vertices.
// graph[i][j] = weight if edge exits else INT_MAX
int minKey(int key[],bool mst[],int V)
{
    int min=INT_MAX,minin=0;
    for(int i=0;i<V;i++)
    {
        if(mst[i]==false && key[i]<min)
          min=key[i],minin=i;
    }
    return minin;
}
int spanningTree(int V,int E,vector<vector<int> > graph)
{
    // code here
    int parent[V],key[V],s=0;
    bool mst[V];
    for(int i=0;i<V;i++)
     key[i]=INT_MAX,mst[i]=false;
    key[0]=0,parent[0]=-1;
    for(int i=0;i<V-1;i++)
    {
       int u=minKey(key,mst,V);
        mst[u]=true;
        for(int v=0;v<V;v++)
        {
            if(graph[u][v] && mst[v]==false && graph[u][v]<key[v])
             parent[v]=u,key[v]=graph[u][v];
        }
    }
   for(int i=0;i<V;i++)
     s+=key[i];
     return s;
}
