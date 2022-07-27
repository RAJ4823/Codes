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

vector<int> temp;
vector<vector<int>> paths;

void dfs(int s, int d, int par, vector<int> g[], vector<bool> &vis)
{
    // vis[s] = true;
    temp.push_back(s);
    if (s == d)
    {
        paths.push_back(temp);
        // return;
    }
    for (auto i : g[s])
    {
        if (i == par)
            continue;
        // if (!vis[i])
        // {
            dfs(i, d, s, g, vis);
            // vis[i] = true;
        // }
    }
    temp.pop_back();
    // vis[s] = false;
    // vis[k] = false;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> g[n + 1];
    vector<bool> vis(n + 1, false);

    f(i, m)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, n, 0, g, vis);
    if (paths.size() == 0)
        cout << "IMPOSSIBLE\n";
    else
    {
        int mini = 0;
        f(i, paths.size())
        {
            if (paths[i].size() < paths[mini].size())
                mini = i;
        }
        cout << paths[mini].size() << endl;
        for (auto i : paths[mini])
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}