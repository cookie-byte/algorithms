#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *adj;

public:
    Graph(int V);
    void addEdge(int u,int w);
    void DFS(int s);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u,int w){
    adj[u].push_back(w);
}

void Graph::DFS(int s){
    bool *visited = new bool[V];
    for(int i = 0;i<V;i++)
        visited[i] = false;
    
    stack<int> st;
    st.push(s);

    while(!st.empty()){
        s = st.top();
        st.pop();

        if(!visited[s]){
            cout<<s<<" ";
            visited[s] = true;
        }

        list<int>::iterator i;
        for(i = adj[s].begin();i!=adj[s].end();++i){
            if(!visited[*i])
                st.push(*i);
        }
    }

}

int main(){
    Graph g(5);
    g.addEdge(1, 0); 
    g.addEdge(0, 2); 
    g.addEdge(2, 1); 
    g.addEdge(0, 3); 
    g.addEdge(1, 4); 
  
    g.DFS(0);
    cout<<endl;
    return 0;
}