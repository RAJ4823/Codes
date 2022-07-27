#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define vll vector<ll>
#define mll map<ll, ll>
#define f(i, n) for (int i = 0; i < (n); i++)
#define ff(i, a, b) for (int i = (a); i < (b); i++)
#define fr(i, n) for (int i = (n); i >= 0; i--)
#define ffr(i, a, b) for (int i = (a); i >= (b); i--)
#define db1(x) cout << #x << " = " << (x) << "\n";
#define db2(x, y) cout << #x << " = " << (x) << " " << #y << " = " << (y) << "\n"
#define SIZE 1000001
#define MOD 1000000007LL

void dfs(vector<int> g[], vector<bool> &vis, int vertex)
{
    vis[vertex] = true;
    for (auto child : g[vertex])
    {
        if (vis[child])
            continue;
        dfs(g, vis, child);
    }
}

int main()
{
    int v, e, components = 0;
    cin >> v >> e;

    vector<int> g[v + 1];
    vector<bool> vis(v + 1, false);
    f(i, e)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    ff(i, 1, v + 1)
    {
        if (vis[i])
            continue;
        dfs(g, vis, i);
        components++;
    }

    cout << components << endl;
    return 0;
}