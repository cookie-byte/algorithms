#include<bits/stdc++.h>
using namespace std;
#define WHITE 0
#define GREY 1
#define BLACK 2
vector<vector<int>> adjList;

void insertNode(int u, int v, int mode){
  if(mode==0){
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }
  else if(mode==1){
      adjList[u].push_back(v);
  }
}

void printList(){
  for(int i=1; i<adjList.size(); i++){
    cout << i << " -> " ;
    for(int j=0; j<adjList[i].size(); j++)
      cout << adjList[i][j] << " ";
    cout << endl;
  }
}

void BFS(int x){
    vector<int> visited;
    visited.resize(adjList.size());
    for(int i=0; i<visited.size(); i++)
      visited[i] = 0;
    queue<int> q;
    int temp;
    q.push(x);
    visited[x] = 1;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        cout << temp << " ";
        for(int i=0; i<adjList[temp].size(); i++){
          if(visited[adjList[temp][i]]==0){
            q.push(adjList[temp][i]);
            visited[adjList[temp][i]] = 1;
          }
        }
    }
    cout << endl;
}

vector<int> visited_dfs;
void DFS_actual(int x){
  visited_dfs[x] = 1;
  cout << x << " ";
  for(int i=0; i<adjList[x].size(); i++){
    if(visited_dfs[adjList[x][i]]==0)
      DFS_actual(adjList[x][i]);
  }
}
void DFS(int x){
  visited_dfs.resize(adjList.size());
  for(int i=0; i<visited_dfs.size(); i++)
    visited_dfs[i] = 0;
  DFS_actual(x);
  cout << endl;
}

vector<int> prev_dfs;
int fcu_dfs(int x){
  visited_dfs[x] = 1;
  for(int i=0; i<adjList[x].size(); i++){
    if(visited_dfs[adjList[x][i]]==1 && prev_dfs[x]!=adjList[x][i])
      return 1;
    else if(visited_dfs[adjList[x][i]] == 0){
      visited_dfs[adjList[x][i]] = 1;
      prev_dfs[adjList[x][i]] = x;
        return fcu_dfs(adjList[x][i]);
    }
  }
  return 0;
}
int findCycleUndirected(){
  visited_dfs.resize(adjList.size());
  prev_dfs.resize(adjList.size());
  for(int i=0; i<visited_dfs.size(); i++){
    visited_dfs[i] = 0;
    prev_dfs[i] = -1;
  }
  return fcu_dfs(1);
}
int fcd_dfs(int x){
  visited_dfs[x] = GREY;
  for(int i=0; i<adjList[x].size(); i++){
    if(visited_dfs[adjList[x][i]]==GREY)
      return 1;
    else if(visited_dfs[adjList[x][i]]==WHITE)
      return fcd_dfs(adjList[x][i]);
  }
  visited_dfs[x] = BLACK;
  return 0;
}
int findCycleDirected(){
  visited_dfs.resize(adjList.size());
  for(int i=0; i<visited_dfs.size(); i++)
    visited_dfs[i] = WHITE;
    return fcd_dfs(1);
}
int findCycle(int mode){
  if(mode==0)
    return findCycleUndirected();
  return findCycleDirected();
}
int main(){
  // 0 = undirected 1 = directed
  int vertices, edges, u , v, mode;
  cin >> vertices >> edges >> mode;
  //cout << vertices << " " << edges << " " << mode << endl;
  adjList.resize(vertices+1);
  for(int i=0; i<edges; i++)
  {
    cin >> u >> v;
    insertNode(u,v,mode);
  }
  printList();
  BFS(1);
  DFS(1);
  cout << findCycle(mode)<< endl;
  return 0;
}

/*

6 7 1
1 2 1 3 1 6 2 4 2 5 3 5 5 4

*/
