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

ll DFS(vvll &g, ll vertex, vector<bool> visited, vll &arr, vll &dp)
{
    if (dp[vertex] != -1)
        return dp[vertex];

    visited[vertex] = true;
    ll count = 0;
    for (auto child : g[vertex])
    {
        if (visited[child])
            continue;
        if (arr[child] < arr[vertex])
        {
            count++;
            count += DFS(g, child, visited, arr, dp);
        }
    }
    return dp[vertex] = count;
}

void solve()
{
    ll n;
    cin >> n;
    vll arr(n);
    f(i, n) cin >> arr[i];
    vvll adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vll dp(n + 1, -1);
    ll ans = 1;

    f(i, n)
    {
        if (dp[i] == -1)
        {
            vector<bool> visited(n, false);
            ans = max(ans, DFS(adj, i, visited, arr, dp) + 1);
        }
    }
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;

    f(i, t)
    {
        cout << "Case #" << i + 1 << ": ";
        solve();
    }
    return 0;
}