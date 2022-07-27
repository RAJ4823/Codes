#include <bits/stdc++.h>
using namespace std;
#define ll long long

void BFS(map<int, vector<int>> &g)
{
    int comp = 1;

    vector<bool> visited(g.size(), false);
    list<int> queue;
    set<int> s; // FOR Components
    for (auto i : g)
        s.insert(i.first);

    while (!s.empty())
    {
        if (queue.empty())
        {
            cout << "\nComponent = " << comp << " : ";
            visited[*s.begin()] = true;
            queue.push_back(*s.begin());
            comp++;
        }

        int x = queue.front();
        cout << x << ' ';
        queue.pop_front();

        for (auto i : g[x])
        {
            if (!visited[i])
                queue.push_back(i);
            visited[i] = true;
            s.erase(i);
        }
    }
}

void input(map<int, vector<int>> &g, int e)
{
    int a, b;
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
}

void display(map<int, vector<int>> &g)
{
    cout << "\nAdjacency List : \n";
    for (auto i : g)
    {
        cout << i.first;
        for (auto j : i.second)
        {
            cout << " -> " << j << ' ';
        }
        cout << "\n";
    }
}
int main()
{
    int v, e;
    cout << "Enter number of vertices : ";
    cin >> v;
    cout << "Enter number of edges : ";
    cin >> e;
    map<int, vector<int>> g;
    input(g, e);
    display(g);
    BFS(g);
    return 0;
}