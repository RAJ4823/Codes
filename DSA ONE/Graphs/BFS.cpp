#include <bits/stdc++.h>
using namespace std;
#define ll long long

void BFS(vector<int> adj[], int s, int v)
{
    vector<bool> visited(v, false);
    list<int> queue;

    visited[s] = true;
    queue.push_back(s);

    while (!queue.empty())
    {
        int vertex = queue.front();
        cout << vertex << ' ';
        queue.pop_front();

        for (auto i : adj[vertex])
        {
            if (!visited[i])
                queue.push_back(i);
            visited[i] = true;
        }
    }
}

void display(vector<int> adj[], int v)
{
    for (int i = 0; i < v; i++)
    {
        cout << i;
        for (auto j:adj[i])
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

    cout << "Adjacency List of Graph : \n";
    display(adj, v);

    cout << "Enter vertex from which you want to start BFS : ";
    cin >> s;
    BFS(adj, s, v);

    return 0;
}