#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vpll vector<pair<ll, ll>>
#define vvll vector<vector<ll>>
#define vll vector<ll>
#define pll pair<ll, ll>
#define mll map<ll, ll>
#define fauto(i, a) for (auto &i : a)
#define f(i, n) for (int i = 0; i < (n); i++)
#define ff(i, a, b) for (int i = (a); i < (b); i++)
#define fr(i, n) for (int i = (n); i >= 0; i--)
#define ffr(i, a, b) for (int i = (a); i >= (b); i--)
#define db1(x) cout << #x << " = " << (x) << "\n";
#define db2(x, y) cout << #x << " = " << (x) << " " << #y << " = " << (y) << "\n"
#define SIZE 1000001
#define MOD 1000000007LL

ll DFS(vll g[], ll v, vector<bool> &vis, vll &arr, ll mini)
{
    vis[v] = true;
    for (auto child : g[v])
    {
        if (vis[child])
            continue;
        mini = min(mini, DFS(g, child, vis, arr, mini));
    }
    return min(mini, arr[v]);
}

int main()
{
    ll v, e, s = 0;
    cin >> v >> e;
    vll arr(v), g[v];

    f(i, v) cin >> arr[i];
    f(i, e)
    {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<bool> vis(v, false);

    ll ans = 0;
    f(i, v)
    {
        if (vis[i])
            continue;
        ans += DFS(g, i, vis, arr, INT_MAX);
    }
    cout << ans << endl;
    return 0;
}