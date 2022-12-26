#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> edge_wigth_pair; // list of pair use kora lagba.tai agai pair create kora nelam
class Graph
{
    int V;                      // amra jehatu adjecence list deya graph make kortache tai amra vertax nibo
    list<edge_wigth_pair> *adj; // make list of pair for adjcence lis

public:
    Graph(int V) // constructor
    {
        this->V = V;
        adj = new list<edge_wigth_pair>[V]; // adjecence er size hova Vertex(V) er shoman
    }

    void add_edge(int u, int v, int w)
    {
        adj[u].push_back(make_pair(v, w)); // u er vitor v && w
        adj[v].push_back(make_pair(u, w)); // v er vitor u && w
    }

    void print_neighbour(int check)
    {
        cout << check << ":";
        for (auto i = adj[check].begin(); i != adj[check].end(); i++)
        {
            cout << "(" << (*i).first << "," << (*i).second << ")";
        }
    }

    void BFS(int source)
    {
        /*
        need a vecror && queue
        */

        vector<bool> visited(V, false); // 1.make vector and make them all false
        queue<int> Q;                   // 2.make a queue

        // first we enter a value in queue

        visited[source] = true; // first make that's position true
        Q.push(source);         // them insert the value

        while (!Q.empty()) // auto insertion
        {
            int u = Q.front(); // capter front;
            cout << u << " ";  // print front
            Q.pop();           // pop the value.so that it's child can enter in queue

            for (auto element : adj[u])
            {
                int v = element.first; // capter first
                if (visited[v] != true)
                {
                    visited[v] = true; // make it true
                    Q.push(v);         // push into the queue
                }
            }
        }
    }
};
int main()
{
    int V, E, source;
    cin >> V >> E >> source;
    Graph g(V);
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g.add_edge(u, v, w);
    }
    // for (int i = 0; i < V; i++)
    // {
    //     g.print_neighbour(i);
    //     cout << endl;
    // }

    cout << endl
         << endl;

    g.BFS(source);
}

/*
7 10 0
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