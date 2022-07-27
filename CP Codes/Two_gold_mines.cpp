//https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/ujjwals-mine-9eacab11/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF INT_MAX
#define f(i, n) for (int i = 0; i < (n); i++)
#define ff(i, a, b) for (int i = (a); i < (b); i++)
#define db2(x, y) cout << #x << " = " << (x) << " | " << #y << " = " << (y) << "\n"

void addEdge(vector<int> adjList[], int a, int b)
{
    adjList[a].push_back(b);
    adjList[b].push_back(a);
}
// BFS for finding shortest path
int shortDistance(vector<int> g[], int v, int source, int destination)
{
    list<int> queue;
    vector<int> dist(v * v, INF);

    queue.push_back(source);
    dist[source] = 0;
    while (!queue.empty())
    {
        int next = queue.front();
        queue.pop_front();

        for (auto i : g[next])
        {
            if (dist[i] == INF)
            {
                dist[i] = dist[next] + 1;
                queue.push_back(i);
            }
        }
    }
    return dist[destination];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int v;
        cin >> v;
        // Declaration
        char mat[v][v];
        vector<int> g[v * v];
        vector<vector<int>> dist;
        int gold[2], player[2];
        int dist1 = INF, dist2 = INF, a = 0, b = 0;

        // Gold and Player position
        f(i, v)
        {
            f(j, v)
            {
                cin >> mat[i][j];
                if (mat[i][j] == '*')
                {
                    gold[a] = (v * i + j);
                    a++;
                }
                if (mat[i][j] == '^')
                {
                    player[b] = (v * i + j);
                    b++;
                }
            }
        }
        // Adding edge between valid pairs
        f(i, v)
        {
            f(j, v - 1)
            {
                if (mat[i][j] != '#' && mat[i][j + 1] != '#')
                    addEdge(g, v * i + j, v * i + j + 1);
                if (mat[j][i] != '#' && mat[j + 1][i] != '#')
                    addEdge(g, v * j + i, v * (j + 1) + i);
            }
        }

        // Searching shortest distance between player to gold
        int p0g0 = shortDistance(g, v, player[0], gold[0]);
        int p1g1 = shortDistance(g, v, player[1], gold[1]);
        int p0g1 = shortDistance(g, v, player[0], gold[1]);
        int p1g0 = shortDistance(g, v, player[1], gold[0]);
        int diff = shortDistance(g, v, gold[0], gold[1]);

        dist1 = min(max(p0g0, p1g1), max(p0g1, p1g0));
        dist2 = min(p0g0, min(p0g1, min(p1g1, p1g0)));
        
        int ans = abs(min(dist1, dist2 + diff));
        if (ans < v*v)
            cout << "Yes\n"
                 << ans << endl;
        else
            cout << "No\n";
    }
    return 0;
}