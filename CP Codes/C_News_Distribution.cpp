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

//! WILL TRY IN FUTURE :(

void dfs(int node, int &count, vector<vector<int>> &adj, vector<bool> &vis)
{
    vis[node] = true;
    count++;
    for (auto neigh : adj[node])
    {
        if (!vis[neigh])
            dfs(neigh, count, adj, vis);
    }
}

void fill(int node, int count, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &ans)
{
    ans[node] = count;
    vis[node] = true;
    for (auto neigh : adj[node])
    {
        if (!vis[neigh])
            fill(neigh, count, adj, vis, ans);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    while (m--)
    {
        int k;
        cin >> k;
        vector<int> temp(k);
        f(i, k) cin >> temp[i];
        for (int i = 0; i < k; i++)
        {
            for (int j = i + 1; j < k; j++)
            {
                adj[temp[i]].push_back(temp[j]);
                adj[temp[j]].push_back(temp[i]);
            }
        }
    }

    vector<bool> vis(n + 1, false), fvis(n + 1, false);
    vector<int> ans(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            int count = 0;
            dfs(i, count, adj, vis);
            fill(i, count, adj, fvis, ans);
        }
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}