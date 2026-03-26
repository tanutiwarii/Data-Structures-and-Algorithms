#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class Graph{
    int V;
    list<int> *l;

public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v){
    l[u].push_back(v);
    }

    void dfs(int u, vector<int> &visited){
        cout<<u<<" ";
        visited[u] = true;

        
    }
};

int main(){

    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(2,4);

    g.dfs();
    return 0;
}