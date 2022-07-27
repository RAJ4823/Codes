#include <bits/stdc++.h>
using namespace std;
#define ll long long

void addEdge(vector<int> adjList[], int a, int b)
{
    adjList[a].push_back(b);
    adjList[b].push_back(a);
}

void printAdjList(vector<int> adjList[], int v)
{
    for (int i = 0; i < v; i++)
    {
        cout << i;
        for (int j = 0; j < adjList[i].size(); j++)
        {
            cout << " -> " << adjList[i][j];
        }
        cout << endl;
    }
}

int main()
{
    int v, e;
    cout << "Enter number of vertices : ";
    cin >> v;
    cout << "Enter number of edges : ";
    cin >> e;

    vector<int> adjList[v];

    cout << "Enter vertices which are connected.\n";
    //verticies must start with 0 and in increasing order because
    //we used array for indexing head
    for (int i = 0; i < e; i++)
    {
        int src, dst;
        cin >> src >> dst;
        addEdge(adjList, src, dst);
    }

    printAdjList(adjList, v);
    return 0;
}