#include<bits/stdc++.h>

using namespace std;

void printSol(int sol[10][10],int N){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cout<<sol[i][j]<<" ";
    }
    cout<<endl;
  }

}

bool isSafe(int maze[10][10],int x,int y,int N){
  if(x>=0 && x<N && y>=0 && y<N && maze[x][y]!=0){
    return true;
  }
  return false;
}
bool solveMazeUtils(int maze[10][10],int sol[10][10],int x,int y,int N){
    if(x==N-1 && y==N-1){
      sol[x][y]=1;
      //printSol(sol,N);
      return true;
    }

    if(isSafe(maze,x,y,N)){
      sol[x][y] = 1;
      for(int i=1;i<=maze[x][y] && i<N;i++){
        if(solveMazeUtils(maze,sol,x,y+i,N)){
          return true;
        }

        if(solveMazeUtils(maze,sol,x+i,y,N)){
          return true;
        }
      }
      sol[x][y] = 0;
      return false;
    }
    return false;
}


void solveMaze(int maze[10][10],int N){
    int sol[10][10];
    for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
        sol[i][j]=0;
      }
    }
    if(solveMazeUtils(maze,sol,0,0,N)==true){
      printSol(sol,N);
    }else{
      cout<<"-1\n";
    }
}

int main(){
  int t;
  cin>>t;
  while(t--){
    int N,i,j;
    cin>>N;
    int maze[10][10];
    for(i=0;i<N;i++){
      for(j=0;j<N;j++){
        cin>>maze[i][j];
      }
    }
    solveMaze(maze,N);
  }
  return 0;
}
