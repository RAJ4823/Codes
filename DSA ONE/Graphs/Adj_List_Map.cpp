#include <bits/stdc++.h>
using namespace std;
#define ll long long

void addEdge(map<int, vector<int>> &adjList, int a, int b)
{
    //If vertex is new than inserted as 0th index
    if (adjList.find(a) == adjList.end()) 
        adjList[a].push_back(a);
    if (adjList.find(b) == adjList.end())
        adjList[b].push_back(b);

    adjList[a].push_back(b);
    adjList[b].push_back(a);
}

void printAdjList(map<int, vector<int>> adjList)
{
    for (auto i:adjList)
    {
        //0th index wil always contain head
        //Because we used map
        cout << i.second[0];
        for (int j = 1; j < i.second.size(); j++)
        {
            cout << " -> " << i.second[j];
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

    map<int,vector<int>> adjList;

    cout << "Enter vertices which are connected.\n";

    for (int i = 0; i < e; i++)
    {
        int src, dst;
        cin >> src >> dst;

        addEdge(adjList, src, dst);
    }

    printAdjList(adjList);
    return 0;
}