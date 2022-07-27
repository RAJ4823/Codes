#include <bits/stdc++.h>
#define ll long long int
#define ld long double
using namespace std;

vector<int> subtrees;
vector<vector<pair<int, int>>> edges;

int dfs(int node, int parent, bool blocked)
{
    int nodes = 1;
    for (auto it : edges[node])
    {
        if (it.first == parent)
            continue;
        int x = dfs(it.first, node, (blocked || it.second));
        nodes += x;
        if (it.second && !blocked)
            subtrees.push_back(x);
    }
    return nodes;
}

void mainSolve()
{
    int n, k;
    cin >> n >> k;
    edges.clear();
    edges.resize(n + 1);
    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
    }
    subtrees.clear();
    dfs(1, 0, false);
    sort(subtrees.begin(), subtrees.end());
    reverse(subtrees.begin(), subtrees.end());
    int infected = n;
    if (infected <= k)
    {
        cout << 0 << endl;
        return;
    }
    for (int i = 0; i < subtrees.size(); i++)
    {
        infected -= subtrees[i];
        if (infected <= k)
        {
            cout << (i + 1) << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        mainSolve();
    }
    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define f(i, n) for (int i = 0; i < (n); i++)
// #define ff(i, a, b) for (int i = (a); i < (b); i++)

// int dfs(int s, vector<vector<pair<int, int>>> &g, vector<bool> &visited, vector<int> &infected, vector<int> &uninfected)
// {
//     visited[s] = true;
//     int count = 1;
//     for (auto i : g[s])
//     {
//         int v = i.first;
//         int w = i.second;
//         if (infected[s] && w == 0)
//             infected[v] = 1;

//         if (!visited[v])
//         {
//             int res = dfs(v, g, visited, infected, uninfected);
//             if (infected[s] && w == 1)
//                 uninfected.push_back(res);
//             count += res;
//         }
//     }
//     return count;
// }
// int main()
// {
//     int t;
//     cin >> t;

//     while (t--)
//     {
//         int n, k;
//         cin >> n >> k;

//         vector<vector<pair<int, int>>> g(n + 1);
//         vector<bool> visited(n + 1, false);
//         vector<int> infected(n + 1, 0);
//         vector<int> uninfected;

//         infected[1] = 1;

//         ff(i, 1, n)
//         {
//             int u, v, w;
//             cin >> u >> v >> w;
//             g[u].push_back({v, w});
//             g[v].push_back({u, w});
//         }

//         dfs(1, g, visited, infected, uninfected);

//         int total = accumulate(infected.begin(), infected.end(), 0);
//         int rem = k - total;
//         sort(uninfected.begin(), uninfected.end());

//         if (rem < 0)
//         {
//             cout << -1 << endl;
//         }
//         else
//         {
//             int i = 0;
//             int x = uninfected.size();
//             while (rem >= uninfected[i] && i < x)
//             {
//                 rem -= uninfected[i];
//                 i++;
//             }
//             cout << x - i << endl;
//         }
//     }
//     return 0;
// }