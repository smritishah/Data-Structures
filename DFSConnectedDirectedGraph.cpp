#include <bits/stdc++.h>
using namespace std;

class Graph {
  
  int V;
  vector<int> *adj;
  bool *visited;
  
  public: Graph(int nodes){
    V = nodes;
    adj = new vector<int>[V];
    visited = new bool[V];
  }
  
  public: void addedge(int u,int v){
      adj[u].push_back(v);
  }
  
  public: void dfs(int v){
      visited[v] = true;
      cout << v << " ";
      for(auto i:adj[v])
          if(!visited[i])
                dfs(i);
  }
};

int main(){
    int nodes,edges,u,v,source;
    cout << "enter number of nodes:" << endl;
    cin >> nodes;
    cout << "enter number of edges:" << endl;
    cin >> edges;
    Graph g(nodes);
    for(int i = 0;i<edges;i++){
        // vertices start from 0
        cout << "enter start and end vertices" << endl;
        cin >> u >> v;
        g.addedge(u,v);
    }
    cout << "enter source:" << endl;
    cin >> source;
    g.dfs(source);
    
	// sample input
	// Graph g(4);
	// g.addEdge(0, 1);
	// g.addEdge(0, 2);
	// g.addEdge(1, 2);
	// g.addEdge(2, 0);
	// g.addEdge(2, 3);
	// g.addEdge(3, 3);
	// g.dfs(2);
    return 0;
}