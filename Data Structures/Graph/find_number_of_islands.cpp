int vis[50][50];
int row[]={-1,-1,-1,0,0,1,1,1};
int col[]={-1,0,1,-1,1,-1,0,1};
void dfs(vector<int> A[],int i,int j,int N,int M)
{
    vis[i][j]=1;
    for(int k=0;k<8;k++)
    {
        if((i+row[k])>=0 && (i+row[k])<N && (j+col[k])>=0 && (j+col[k])<M && !vis[row[k]+i][col[k]+j] && A[row[k]+i][col[k]+j])
          dfs(A,(i+row[k]),(j+col[k]),N,M);
    }
}
int findIslands(vector<int> A[], int N, int M)
{
    
    // Your code here
    int count = 0;
    vis[N][M];
    memset(vis,0,sizeof(vis)); 
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<M;j++)
        {
            if(A[i][j] && !vis[i][j])
            {
              dfs(A,i,j,N,M);
              ++count;
            }
        }
    }
    return count;
}

