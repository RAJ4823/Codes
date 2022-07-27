#include <bits/stdc++.h>
using namespace std;
#define ll long long

void DFS(vector<int> g[], int vertex, vector<bool> visited)
{
    //Take action on vertex after entering the vertex
    visited[vertex] = true;
    cout << vertex << ' ';

    for(auto child :g[vertex])
    {
        if(visited[child]) continue;

        //Take action on child before entering the child node
        DFS(g,child,visited);
        //Take action on child after entering the child node
    }
    //Take action on vertex before exiting the vertex
}

void display(vector<int> adj[], int v)
{

    cout << "Adjacency List of Graph : \n";
    for (int i = 0; i < v; i++)
    {
        cout << i;
        for (auto j : adj[i])
        {
            cout << " -> " << j;
        }
        cout << endl;
    }
}
void input(vector<int> adj[], int e)
{
    cout << "Enter connected vertices.\n";
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

int main()
{
    int v, e, s;
    cout << "Enter number of vertices : ";
    cin >> v;
    cout << "Enter number of edges : ";
    cin >> e;
    
    vector<int> adj[v];
    input(adj, e); // Input the Graph

    display(adj, v);
    cout << "Enter source vertex : ";
    cin >> s;

    vector<bool> visited(v, false);
    DFS(adj, s,  visited);

    return 0;
}
