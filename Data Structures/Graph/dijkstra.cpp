#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
#define maxn 10000
#define inf 1e9+1

vector<ii> grafo[maxn];
int dist[maxn];

void dijkstra(int init){
	for(int x = 0; x < maxn; x++){
		dist[x] = inf;
	}
	priority_queue<ii, vector<ii>, greater<ii>> heap;
	dist[init] = 0;
	heap.push(make_pair(dist[init], init));
	while(!heap.empty()){
		int d = heap.top().first;
		int index = heap.top().second;
		heap.pop();
		if(d > dist[index]){
			continue;
		}
		for(int x = 0; x < (int) grafo[index].size(); x++){
			int d = grafo[index][x].first;
			int p_onde = grafo[index][x].second;
			if(d + dist[index] < dist[p_onde]){
				dist[p_onde] = d + dist[index];
				heap.push(make_pair(dist[p_onde], p_onde));
			}
		}
	}
}

void clearGraph(){
	for(int x = 0; x < maxn; x++){
		grafo[x].clear();
	}
}

void addEdge(int from, int to, int cost){
	grafo[from].push_back(make_pair(cost, to));
    grafo[to].push_back(make_pair(cost, from));
}

int main(){
	int n;
	cin >> n;
	string str;
	
	while(n--){
		int n_cells, n_edges;
		cin >> n_cells >> n_edges;
		while(n_edges--){
			int a, b, c;
			cin >> a >> b >> c;
			addEdge(a, b, c);
		}
        int qt_cells = n_cells;
		int cont = 0;
		while(n_cells--){
			dijkstra(cont);
            cout << "Dist from " << cont << endl;
			for(int x = 0; x < qt_cells; x++){
                if(x != cont) cout << "to " << x << " : " << dist[x] << endl;
            }
            cont++;
            cout << endl;
        }
		clearGraph();
	}
}