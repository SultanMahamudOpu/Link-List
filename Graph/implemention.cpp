#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> edge_wigth_pair;
class Graph
{
    int V;
    list<edge_wigth_pair> *adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new list<edge_wigth_pair>[V];
    }

    void add_edge(int u, int v, int w)
    {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    void print_neighbour(int check)
    {
        cout << check << ":";
        for (auto i = adj[check].begin(); i != adj[check].end(); i++)
        {
            cout << "(" << (*i).first << "," << (*i).second << ")";
        }
    }
};
int main()
{
    int V, E;
    cin >> V >> E;
    Graph g(V);
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.add_edge(u, v, w);
    }
    for (int i = 0; i < V; i++)
    {
        g.print_neighbour(i);
        cout << endl;
    }
}

/*
7 10
0 1 7
0 2 1
0 5 3
1 3 11
2 3 3
3 6 1
6 5 2
6 4 4
5 4 4
2 5 8
*/