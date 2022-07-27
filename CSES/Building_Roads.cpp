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

void dfs(int s, vector<bool> &vis, vector<int> g[])
{
    vis[s] = true;
    for (auto i : g[s])
    {
        if (!vis[i])
            dfs(i, vis, g);
        vis[i] = true;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> g[n + 1];
    vector<bool> vis(n + 1, false);
    vector<pair<int, int>> ans;

    f(i, m)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int j = 0, i = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (j != 0)
                ans.push_back({j, i});
            dfs(i, vis, g);
            j = i;
        }
    }

    cout << ans.size() << endl;
    if (ans.size() > 0)
    {
        for (auto i : ans)
            cout << i.first << ' ' << i.second << endl;
    }

    return 0;
}